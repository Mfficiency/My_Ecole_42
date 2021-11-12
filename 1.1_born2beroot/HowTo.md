# Born2beroot
Step by step guide on how to do it.

## TODO : Reinstall at home and rewrite last steps

## Prep
### Install VirtualBox
	1. Go to Managed Software Center
	2. Search for VirtualBox
	3. Install VirtualBox

### Downloading Debian (https://www.wikihow.com/Install-Debian-in-Virtualbox)
	1. https://www.debian.org/distrib/netinst
	2. amd64 : https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/debian-11.1.0-amd64-netinst.iso 

### Launch VirtualBox

### Create New VM
	1. Click New
	2. Name: mmeersma42
	3. Machine folder: /goinfre/mmeersma/VM
	4. Type: Linux
	5. Version: Debian (64-bit)
	6. Click Continue
	7. Memory size: 1024 MB
	8. Click Continue
	9. Hard disk: Create a virtual hard disk now
	10. Click Create
	11. Hard disk file type: VDI
	12. Click Continue
	13. Storage on physical hard disk: Dynamically allocated
	14. Click Continue
	15. File location: /goinfre/mmeersma/VM/mmeersma42/mmeersma42.vdi
	16. Size: 8BG
	17. Click Create

### Start the VM
    1.  Doubleclick the VM 
    2.  Select the folder icon
    3.  Click Add
    4.  Select the iso file
    5.  Click Choose
    6.  Click Start

Change window size to 200% "Virtual Screen 1 >"  
![Alt text](Screen%20Shot%202021-11-11%20at%203.00.46%20PM.png)

##  Install Debian (https://www.wikihow.com/Install-Debian)
	1.	Click Install
	2.	Language: English
	3.	country: Other, Europe, Switzerland
	4.	Locale settings: United States
	5.	Keymap to use: American English
	6.	Hostname: mmeersma42
	7.	Domain name: Continue
	8.	Root password: *Password*
	9.	Full name for new user: mmeersma
	10.	Username for your account: mmeersma
	11.	password: *Password*

### Partition disks
	1. Guided - use entire disk and set up encrypted LVM
	2. Select harddisk
	3. Separate / home partition
	4. Yes
	5. Encryption passphrase: *Password*
	6. If weak, yes
	7. Amount of volume: max
	8. Finish partitioning
	9. Write changes: yes
	10. Scan extra installation media?: No?
	11. Mirror country: Switzerland
	12. Debian archive mirror: deb.debian.org
	13. HTTP proxy: none
	14. Participate in the package usage survey?: No
	15. Choose software to install: SSH server only & Standard system utilities (if you mess up here, you can install them later using $ tasksel --new-install )
	16. install the grub bootloader: Yes
	17. select dev/sda
	18. Continue

## Config 
### Login
	1. use login

### Check partitions
	$ lsblk
![Alt text](Screen%20Shot%202021-11-12%20at%2012.48.03%20PM.png)

### Change user
su - (change to root)
su *username* (change to  username)

### Install sudo
1. start as root
2. $ apt install sudo

### Create groups
1. $ sudo addgroup user42
2. $ sudo adduser mmeersma user42
3. $ sudo apt update

### Config SSH
1. (if ssh not installed yet) $ sudo apt install openssh-server
2. $ sudo nano /etc/ssh/sshd_config
3. change line "#Port 22" to "Port 4242"
4. "#PermitRootLogin prohibit-password" to "PermitRootLogin no" -> 
5. save (ctrl + o, enter) 
6. exit (ctrl + x)
7. $ sudo nano /etc/ssh/ssh_config
8. change line "#Port 22" to "Port 4242"
9. save and exit
10. Check the status: $ sudo service ssh status (It should be active (running).)

### Install UFW
