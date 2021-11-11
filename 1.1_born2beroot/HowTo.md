# Born2beroot
Step by step guide on how to do it.

## TODO : Reinstall at home and rewrite last steps

## Install VirtualBox
	1. Go to Managed Software Center
	2. Search for VirtualBox
	3. Install VirtualBox
## Downloading Debian (https://www.wikihow.com/Install-Debian-in-Virtualbox)
	1. https://www.debian.org/distrib/netinst
	2. amd64 : https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/debian-11.1.0-amd64-netinst.iso 
## Launch VirtualBox
## Create New VM
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
## Start the VM
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
	4.	Keymap to use: American English
	5.	Hostname: mmeersma42
	7.	Domain name: Continue
	8.	Root password: admin123 / admin
	9.	Full name for new user: mmeersma
	10.	Username for your account: mmeersma
	10.	password: admin123 / admin
### Partition disks
1. Guided - use entire disk and set up encrypted LVM
2. Select harddisk
3. Separate / home partition
4. Yes
5. Encryption passphrase: admin123 / admin
6. If weak, yes
7. Amount of volume: max
8. Finish partitioning
9. Write changes: yes
10. Scan extra installation media?: No?
11. Mirror country: Switzerland
12. Debian archive mirror: deb.debian.org
13. HTTP proxy: none
14. Participate in the package usage survey?: No
15. Choose software to install: SSH server only?
16. install the grub bootloader: Yes
17. select dev/sda
18. Continue
## Getting started
1. installadmin
admin
login: mmeersma
admin
doneapt




