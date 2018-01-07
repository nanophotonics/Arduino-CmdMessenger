/*
 * This example writes different commands
 * to a buffer before sending them to the PC
 */

#include <CmdMessenger.h>

// create CmdMessenger object
CmdMessenger cmd = CmdMessenger(SerialUSB);

// list of commands
enum {
  test_command
};

void setup() {
  SerialUSB.begin(115200); // initialise serial communication  
}

void loop() {

  int a = 2;
  int b = 30;

  // send variable a in binary format
  cmd.sendBinCmd(test_command, a, true);  // the boolean argument indicates that this command should be written to the buffer

  // send variable a and b in binary format
  cmd.sendCmdStart(test_command, true);  // the boolean argument indicates that this command should be written to the buffer
  cmd.sendCmdBinArg(a, true);
  cmd.sendCmdBinArg(b, true);
  cmd.sendCmdEnd(true);  

  SerialUSB.println("data in buffer:");  
  cmd.sendBufferedCmd();  // send all commands in buffer
  
  delay(1000);
}

