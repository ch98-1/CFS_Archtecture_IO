Copyright (C) 2014-2015  Corwin Hansen

Very simple assembly code and assembled executable memory.
All code is in GNU_GPL-v3
Copy assembled binary files (.bin files) to folder of your choice.
Run compiled program with biary file directory as first command line argument.
Example:
CFS_CLI.exe Apps/Hello_World.bin

Open in hex editor to view result.


To assemble a assembly code, run compiled program with assembly text file as first argument and destination binary file directory as second argument.
This will create a assembled binary file that you can run like example above.

Example:
CFS_CLI.exe Apps/Hello_World.txt Result/Hello_World.bin
CFS_CLI.exe Result/Hello_World.bin