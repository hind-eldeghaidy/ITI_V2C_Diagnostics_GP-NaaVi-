import RPi.GPIO as GPIO
import time

# Define GPIO pins for motor control
in1 = 24
in2 = 23
in3 = 27
in4 = 17
en1 = 25
en2 = 22

# Define GPIO pins for ultrasonic sensors
trigger_pins = [10, 9]    # Ultrasonic sensor trigger pins
echo_pins = [14, 15]      # Ultrasonic sensor echo pins

# Ultrasonic sensor connected to pins 11 (TRIG) and 18 (ECHO)
trigger_pins.append(11)
echo_pins.append(18)

# Ultrasonic sensor connected to pins 8 (TRIG) and 26 (ECHO)
trigger_pins.append(8)
echo_pins.append(26)

# Ultrasonic sensor thresholds
obstacle_distance = 60  # Distance threshold to detect an obstacle
parking_distance = 120  # Minimum distance required for parking space

# Setup GPIO
GPIO.setmode(GPIO.BCM)

# Setup ultrasonic sensors
for trigger_pin, echo_pin in zip(trigger_pins, echo_pins):
    GPIO.setup(trigger_pin, GPIO.OUT)
    GPIO.setup(echo_pin, GPIO.IN)

# Setup motor pins
GPIO.setup(in1, GPIO.OUT)
GPIO.setup(in2, GPIO.OUT)
GPIO.setup(in3, GPIO.OUT)
GPIO.setup(in4, GPIO.OUT)
GPIO.setup(en1, GPIO.OUT)
GPIO.setup(en2, GPIO.OUT)

# Setup PWM for motor speed control
p1 = GPIO.PWM(en1, 100)  # Frequency is 100 Hz
p2 = GPIO.PWM(en2, 100)  # Frequency is 100 Hz
p1.start(0)  # Initial duty cycle of 0 (motor stopped)
p2.start(0)  # Initial duty cycle of 0 (motor stopped)

# Function to control motors with speed
def control_motors(enable_pin, in1_pin, in2_pin, direction, speed):
    GPIO.output(in1_pin, GPIO.LOW if direction == 'forward' else GPIO.HIGH)
    GPIO.output(in2_pin, GPIO.HIGH if direction == 'forward' else GPIO.LOW)
    enable_pin.ChangeDutyCycle(speed)

def stop_motors(enable_pin):
    enable_pin.ChangeDutyCycle(0)  # Set duty cycle to 0 (motor stopped)

# Function to calculate ultrasonic distance
def ultrasonic_distance(TRIG, ECHO):
    GPIO.output(TRIG, False)
    time.sleep(0.1)

    GPIO.output(TRIG, True)
    time.sleep(0.00001)
    GPIO.output(TRIG, False)

    while GPIO.input(ECHO) == 0:
        pulse_start = time.time()

    while GPIO.input(ECHO) == 1:
        pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start
    distance = pulse_duration * 17150
    distance = round(distance, 2)
    return distance

# Function for auto parking
def auto_parking():
    try:
        while True:
            # Step 1: Move forward until obstacle
            control_motors(p1, in1, in2, 'forward', 60)
            control_motors(p2, in3, in4, 'forward', 60)
            while True:
                distances = [ultrasonic_distance(trigger_pin, echo_pin) for trigger_pin, echo_pin in zip(trigger_pins, echo_pins)]
                if min(distances) < obstacle_distance:
                    break

            # Step 2: Turn left
            stop_motors(p1)
            stop_motors(p2)
            control_motors(p1, in1, in2, 'backward', 60)
            control_motors(p2, in3, in4, 'forward', 60)
            time.sleep(1)  # Adjust time as needed for the turn

            # Step 3: Continue until space
            while True:
                distances = [ultrasonic_distance(trigger_pin, echo_pin) for trigger_pin, echo_pin in zip(trigger_pins, echo_pins)]
                if min(distances) >= parking_distance:
                    break

            # Step 4: Adjust position
            stop_motors(p1)
            stop_motors(p2)
            control_motors(p1, in1, in2, 'forward', 60)
            control_motors(p2, in3, in4, 'forward', 60)
            time.sleep(1)  # Adjust time as needed for adjustment

            # Step 5: Stop
            stop_motors(p1)
            stop_motors(p2)
            print("Parking successful!")
            break  # Exit the loop after parking

    except KeyboardInterrupt:
        GPIO.cleanup()

# Call the auto_parking function to initiate parking
auto_parking()
