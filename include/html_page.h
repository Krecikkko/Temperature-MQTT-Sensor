#ifndef HTML_PAGE_H
#define HTML_PAGE_H

#include <pgmspace.h>

const char HTML_PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>ESP8266 Dashboard</title>
  <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
  <style>
    body { font-family: Arial, sans-serif; text-align: center; padding: 20px; }
    h1 { color: #4caf50; }
    canvas { max-width: 100%; height: auto; }
  </style>
</head>
<body>
  <h1>ESP8266 Temperature</h1>
  <div><strong>Current:</strong> <span id="temp">--.-</span> °C</div>
  <canvas id="tempChart" width="400" height="200"></canvas>

  <script>
    const ctx = document.getElementById('tempChart').getContext('2d');
    const tempData = {
      labels: [],
      datasets: [{
        label: 'Temperature (°C)',
        data: [],
        borderColor: '#4caf50',
        fill: false,
        tension: 0.1
      }]
    };

    const tempChart = new Chart(ctx, {
      type: 'line',
      data: tempData,
      options: {
        animation: false,
        scales: {
          x: {
            title: { display: true, text: 'Time' }
          },
          y: {
            suggestedMin: 10,
            suggestedMax: 40
          }
        }
      }
    });

    function updateData() {
      fetch('/data')
        .then(res => res.json())
        .then(data => {
          const now = new Date();
          const label = now.getHours().toString().padStart(2, '0') + ':' +
                        now.getMinutes().toString().padStart(2, '0') + ':' +
                        now.getSeconds().toString().padStart(2, '0');

          document.getElementById('temp').textContent = data.temperature;

          tempData.labels.push(label);
          tempData.datasets[0].data.push(data.temperature);

          if (tempData.labels.length > 20) {
            tempData.labels.shift();
            tempData.datasets[0].data.shift();
          }

          tempChart.update();
        })
        .catch(console.error);
    }

    setInterval(updateData, 5000);
    updateData(); // initial
  </script>
</body>
</html>
)rawliteral";

#endif // HTML_PAGE_H