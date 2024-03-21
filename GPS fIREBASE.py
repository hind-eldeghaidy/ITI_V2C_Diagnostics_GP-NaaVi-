import pyrebase
import serial
import pynmea2

firebaseConfig={
  "apiKey": "AIzaSyA0zlVqlo3-L7VGFbPboHQC894U2NcRdQk",
  "authDomain": "gps-tracker-e9756.firebaseapp.com",
  "databaseURL": "https://gps-tracker-e9756-default-rtdb.firebaseio.com",
  "projectId": "gps-tracker-e9756",
  "storageBucket": "gps-tracker-e9756.appspot.com",
  "messagingSenderId": "1022969129382",
  "appId": "1:1022969129382:web:5517620bb1f52f252d0767"
    }

firebase=pyrebase.initialize_app(firebaseConfig)
db=firebase.database()

while True:
        port="/dev/ttyAMA0"
        ser=serial.Serial(port, baudrate=9600, timeout=0.5)
        dataout = pynmea2.NMEAStreamReader()
        newdata=ser.readline()
        n_data = newdata.decode('latin-1')
        if n_data[0:6] == '$GPRMC':
                newmsg=pynmea2.parse(n_data)
                lat=newmsg.latitude
                lng=newmsg.longitude
                gps = "Latitude=" + str(lat) + " and Longitude=" + str(lng)
                print(gps)
                data = {"LAT": lat, "LNG": lng}
                db.update(data)
                print("Data sent")