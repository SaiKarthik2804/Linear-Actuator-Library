# LinearActuatorLibrary for ESP32
## Description
This Library is written for interfacing a BTS7960 High Current DC Motor Drive with ESP 32. Links to the hardware are given below.

## Hardware:
1. High Current DC Motor Drive - 43A :- https://www.firgelliauto.com/products/high-current-dc-motor-drice-43a
2. Feedback Rod Linear Actuators     :- https://www.firgelliauto.com/products/feedback-rod-actuator?variant=2632767555
3. ESP32 Dev Module Microcontroller  :- https://www.amazon.com/ESP32-WROOM-32-Development-ESP-32S-Bluetooth-Arduino/dp/B084KWNMM4


## Installation

1. **Clone the Repository**:
   ```sh
   git clone https://github.com/SaiKarthik2804/Linear-Actuator-Library.git
   ```

2. **Move to Arduino Libraries Folder**:
   Copy the `LinearActuator` folder to your Arduino libraries directory, typically located at `~/Documents/Arduino/libraries/`.

## Usage

### Example

Here's a basic example to get you started:

```cpp
#include <Arduino.h>
#include <LinearActuator.h>

LinearActuator actuator;

void setup() {
  actuator.init(2, 3, 4, 34);  // Initialize with pins for Fwd, Rev, En, and Pot
  actuator.set_limits(0, 4095);  // Set the lower and upper limits for the actuator
  actuator.set_end_limit_threshold(50);  // Set end limit threshold value
  Serial.begin(115200);
}

void loop() {
  int pos = actuator.get_raw_pos();  // Get raw position
  float mappedPos = actuator.get_pos();  // Get position as percentage
  Serial.print("Raw Position: ");
  Serial.print(pos);
  Serial.print(" Mapped Position: ");
  Serial.println(mappedPos);

  actuator.move_actuator(50);  // Move actuator forward with 50% speed
  delay(2000);
  actuator.move_actuator(-50);  // Move actuator backward with 50% speed
  delay(2000);
}
```

### Functions

#### Methods

- `void init(int Fwd_Pin, int Rev_Pin, int En_Pin, int Pot_Pin)`
  - Initialize the actuator with the specified pins.

- `void set_state(bool state)`
  - Set the state of the actuator (enabled or disabled).
  - takes input values (HIGH or LOW)

- `void set_limits(int Lower_Limit, int Upper_Limit)`
  - Set the operational limits for the actuator.
  - takes input values range of (0,4095)

- `void set_end_limit_threshold(float end_threshold_value)`
  - Set the end limit threshold value.
  - takes input values range of (0,100) as percentage.

- `int get_raw_pos()`
  - return the raw analog position value from the potentiometer.

- `float get_pos()`
  - returns the position as a percentage of the total stroke.

- `void move_actuator(int Speed)`
  - Move the actuator at the specified speed (-100 to 100).

- `void set_alpha(float a)`
  - Set the alpha value for the exponential moving average filter.

- `int ema()`
  - returns the exponentially smoothed value of the raw analog position value.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any enhancements or bug fixes.


## Acknowledgments

- Thanks to the contributors of the Arduino community for their valuable resources and support.
