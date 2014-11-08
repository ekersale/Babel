#include "ACommandsValue.hh"

// int		cmdVal(PacketInfo *packet)
// {
//   std::vector<int>	ints;
//   std::vector<char *>	chars;
//   char			cmd;
  
//   ints = packet->getInts();
//   chars = packet->getChars();
//   cmd = packet->getCmd();
//   if (methodPtr.find(cmd) != methodPtr.end())
//     (this->*methodPtr[cmd])(chars, ints);
//   else
//     return (-1);
//   return (0);
// }

int		main()
{
  ACommandsValue cmd;
  PacketInfo	packet;
  std::vector<char *> chars;
  std::vector<int> ints;

  packet.setCmd(14);
  cmd.cmdVal(&packet);
  return (0);
}
