import RPi.GPIO as GPIO
import time

# Define GPIO pins for motor control
in1 = 24
in2 = 23
in3 = 27
in4 = 17
en1 = 25
en2 = 22

# Define GPIO pins for ultrasonic sensor
trigger_pin = 10  # Ultrasonic sensor trigger pin
echo_pin = 14     # Ultrasonic sensor echo pin

# Setup GPIO
GPIO.setmode(GPIO.BCM)

# Setup ultrasonic sensor
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
def control_motors(pwm, in1_pin, in2_pin, speed):
    GPIO.output(in1_pin, GPIO.LOW if speed > 0 else GPIO.HIGH)
    GPIO.output(in2_pin, GPIO.HIGH if speed > 0 else GPIO.LOW)
    pwm.ChangeDutyCycle(abs(speed))

# Function to calculate speed using a formula
def calculate_speed(distance):
    # Calculate speed based on distance
    min_speed = 10   # Minimum speed
    max_speed = 100  # Maximum speed
    speed = min_speed + (max_speed - min_speed) * (distance / 200)  # Adjust the formula to fit your needs
    
    # Ensure speed is within the valid range of min_speed to max_speed
    speed = max(min_speed, min(speed, max_speed))
    
    return speed

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

def automatic_cruise_control():
    try:
        while True:
            distance = ultrasonic_distance(trigger_pin, echo_pin)

            # Calculate speed based on distance
            speed = calculate_speed(distance)

            # Control motors based on speed
            control_motors(p1, in1, in2, speed)
            control_motors(p2, in3, in4, speed)

            time.sleep(0.1)

    except KeyboardInterrupt:
        GPIO.cleanup()

# Call the automatic cruise control function
automatic_cruise_control()
