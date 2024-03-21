window.onload = function() {
  var ctx = document.getElementById('chart').getContext('2d');
  var config = {
      type: 'gauge',
      data: {
          datasets: [{
              data: [50], // Initial value at the middle
              backgroundColor: ['transparent', 'transparent'] // No initial color
          }]
      },
      options: {
          responsive: true,
          title: {
              display: true,
              text: 'My Engine'
          },
          layout: {
              padding: {
                  bottom: 30
              }
          },
          needle: {
              radiusPercentage: 2,
              widthPercentage: 3.2,
              lengthPercentage: 80,
              color: 'rgba(0, 0, 0, 1)',
              needleValue: 50 // Initial value at the middle
          },
          valueLabel: {
              formatter: Math.round
          }
      }
  };

  var myGauge = new Chart(ctx, config);

  // Connect to MQTT broker for the gauge chart
  var gaugeClient = new Paho.MQTT.Client("e3915457a38d49d6acaaa5c6b1361a77.s1.eu.hivemq.cloud", Number(8884), "gauge-client");

  gaugeClient.onConnectionLost = function(responseObject) {
      if (responseObject.errorCode !== 0) {
          console.log("Gauge Client Connection lost:", responseObject.errorMessage);
      }
  };

  gaugeClient.onMessageArrived = function(message) {
      console.log("Received gauge value:", message.payloadString);
      var value = parseFloat(message.payloadString);
      
      if (!isNaN(value)) {
          // Update chart data with fetched data
          config.data.datasets[0].data = [value];

          // Define colors for different ranges
          var backgroundColor;
          if (value < 15) {
              backgroundColor = ['blue','transparent']; // Blue for value less than 15
          } else if (value >= 15 && value < 25) {
              backgroundColor = ['green','transparent']; // Green for value between 15 and 25
          } else {
              backgroundColor = ['red','transparent']; // Red for value greater than or equal to 25
          }
          
          config.data.datasets[0].backgroundColor = backgroundColor;

          // Move the needle to the appropriate position
          config.options.needle.needleValue = value;

          // Update the chart
          myGauge.update();
          
          console.log("Received gauge value:", value);
      } else {
          console.error('Invalid gauge value:', message.payloadString);
      }
  };

  var gaugeOptions = {
      useSSL: true,  // Change to false if not using SSL
      userName: "Naavi",  // Change to your MQTT username
      password: "Na123456",  // Change to your MQTT password
      onSuccess: function() {
          console.log("Connected to MQTT broker for gauge chart.");
          gaugeClient.subscribe("sensor/value2");
          console.log("Subscribed to topic 'sensor/value2' for gauge chart");
      },
      onFailure: function (message) {
          console.error("Gauge Client Connection failed: " + message.errorMessage);
      }
  };

  gaugeClient.connect(gaugeOptions);

  // Connect to MQTT broker for the tire indicator
  var tireClient = new Paho.MQTT.Client("e3915457a38d49d6acaaa5c6b1361a77.s1.eu.hivemq.cloud", Number(8884), "tire-client");

  tireClient.onConnectionLost = function(responseObject) {
      if (responseObject.errorCode !== 0) {
          console.log("Tire Client Connection lost:", responseObject.errorMessage);
      }
  };

  tireClient.onMessageArrived = function(message) {
      console.log("Received tire status:", message.payloadString);
      var tireStatus = parseInt(message.payloadString);
      
      // Update tire indicator based on the received status
      var tireIndicator = document.getElementById('tire-indicator');
      if (tireStatus === 1) {
          tireIndicator.classList.remove('change-not-needed');
          tireIndicator.classList.add('change-needed');
      } else {
          tireIndicator.classList.remove('change-needed');
          tireIndicator.classList.add('change-not-needed');
      }
  };

  var tireOptions = {
      useSSL: true,  // Change to false if not using SSL
      userName: "Naavi",  // Change to your MQTT username
      password: "Na123456",  // Change to your MQTT password
      onSuccess: function() {
          console.log("Connected to MQTT broker for tire indicator.");
          tireClient.subscribe("sensor/value3");
          console.log("Subscribed to topic 'sensor/value3' for tire indicator");
      },
      onFailure: function (message) {
          console.error("Tire Client Connection failed: " + message.errorMessage);
      }
  };

  tireClient.connect(tireOptions);
};
