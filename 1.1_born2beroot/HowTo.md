# Born2beroot
Step by step guide on how to do it.

#### TODO : Reinstall at home and rewrite last steps

- [Born2beroot](#born2beroot)
			- [TODO : Reinstall at home and rewrite last steps](#todo--reinstall-at-home-and-rewrite-last-steps)
- [Setting up virtual box](#setting-up-virtual-box)
	- [Install VirtualBox](#install-virtualbox)
	- [Downloading Debian (https://www.wikihow.com/Install-Debian-in-Virtualbox)](#downloading-debian-httpswwwwikihowcominstall-debian-in-virtualbox)
	- [Launch VirtualBox](#launch-virtualbox)
	- [Create New VM](#create-new-vm)
	- [Start the VM](#start-the-vm)
- [Installing Debian (https://www.wikihow.com/Install-Debian)](#installing-debian-httpswwwwikihowcominstall-debian)
	- [Partition disks](#partition-disks)
- [Configuring your machine](#configuring-your-machine)
	- [Login](#login)
	- [Check partitions](#check-partitions)
	- [Change user](#change-user)
	- [Install sudo](#install-sudo)
	- [Create groups](#create-groups)
	- [Config SSH](#config-ssh)
	- [Install UFW](#install-ufw)
	- [Config Sudo](#config-sudo)
	- [Setup strong password policy](#setup-strong-password-policy)
- [Network adapter config](#network-adapter-config)
- [Monitoring.sh](#monitoringsh)
	- [Preparation before running monitoring.sh](#preparation-before-running-monitoringsh)
	- [Install net tools](#install-net-tools)
	- [Create file](#create-file)
	- [Cron](#cron)
	- [Signature](#signature)
- [Eval](#eval)
	- [General instructions](#general-instructions)
	- [Project overview](#project-overview)
		- [How does it works?](#how-does-it-works)
		- [Why Debian?](#why-debian)
		- [Differences between CentOS and Debian](#differences-between-centos-and-debian)
		- [What it's purpose?](#what-its-purpose)
		- [What is virtual machine?](#what-is-virtual-machine)
		- [Diff between aptitude and apt?](#diff-between-aptitude-and-apt)
		- [What is AppArmor?](#what-is-apparmor)
		- [Monitor.sh should be running every 10 min](#monitorsh-should-be-running-every-10-min)
	- [Simple setup](#simple-setup)
		- [What is SSH?](#what-is-ssh)
	- [User](#user)
		- [My login](#my-login)
		- [Create a new user](#create-a-new-user)
		- [How your script works?](#how-your-script-works)
		- [Part two: What to check?](#part-two-what-to-check)
- [Other questions](#other-questions)

# Setting up virtual box
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

#  Installing Debian (https://www.wikihow.com/Install-Debian)
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

## Partition disks
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

# Configuring your machine 
same steps less/different detail: https://github.com/HEADLIGHTER/Born2BeRoot-42
## Login
	1. use login

## Check partitions
	$ lsblk
![Alt text](Screen%20Shot%202021-11-12%20at%2012.48.03%20PM.png)

## Change user
su - (change to root)
su *username* (change to  username)

## Install sudo
1. start as root
2. $ apt install sudo

## Create groups
Video explaining groups: https://www.youtube.com/watch?v=7cRaGaIZQlo
1. $ sudo addgroup user42
2. $ sudo adduser mmeersma user42
3. $ sudo apt update

## Config SSH
Video explaining ssh: https://www.youtube.com/watch?v=qWKK_PNHnnA
1. (if ssh not installed yet) $ sudo apt install openssh-server
2. $ sudo nano /etc/ssh/sshd_config
3. change line "#Port 22" to "Port 4242"
4. "#PermitRootLogin prohibit-password" to "PermitRootLogin no" -> 
5. save (ctrl + o, enter) 
6. exit (ctrl + x)
7. $ sudo nano /etc/ssh/ssh_config
8. change line "#Port 22" to "Port 4242"
9. save and exit
10. Check the status: $ sudo service ssh status  (It should be active (running).)

## Install UFW
Video explaining UFW: https://youtu.be/-CzvPjZ9hp8?t=170
1. $ sudo apt install ufw
2. $ sudo ufw enable
3. $ sudo ufw allow 4242
4. $ sudo ufw status  It's should be active with 4242 and 4242(v6) ports allow
from anywhere

## Config Sudo
1. $ sudo touch /etc/sudoers.d/sudoconfig
2. $ sudo mkdir /var/log/sudo  (for sudo log files, yes)
3. $ sudo nano /etc/sudoers.d/sudoconfig  
   1. then write next lines in our new file:  
```
Defaults	passwd_tries=3    
Defaults	badpass_message="Incorrect password"
Defaults	log_input,log_output  
Defaults	iolog_dir="/var/log/sudo"   
Defaults	requiretty   
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin" 
```

## Setup strong password policy
Save this until last
1. $ sudo nano /etc/login.defs
2. replace next lines:
```
PASS_MAX_DAYS    99999 -> PASS_MAX_DAYS    30    <- line 160 you can easly reach it with ctrl+_ in nano
PASS_MIN_DAYS    0     -> PASS_MIN_DAYS    2     
```    

PASS_WARN_AGE is 7 by defaults anyway so just ignore it.
3. $ sudo apt install libpam-pwquality
4. $ sudo nano /etc/pam.d/common-password
5. Add to the end of the "password requisite pam_pwqiality.so retry=3" line next parameters

```
minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

You should get_next_line(ha-ha.):
"password requisite pam_pwqiality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root"

6. Now you have to change all your passwords according to your new password policy
```
$ passwd      <- change user password
$ sudo passwd <- change root password
```

# Network adapter config
You may not be able to connect to your VM via SSH with standard settings in
VirtualBox. There is a way to fix it!

1. Turn off your VM
2. Go to your VM settings in VirtualBox
3. Network -> Adapter 1 -> Advanced -> Port forwarding
4. Add new rule (little green button on right top side. and next parameters:
```
Protocol       Host IP       Host Port       Guest IP       Guest Port
TCP            127.0.0.1     4242            10.0.2.15      4242      
```
5. Start your VM again & login
6. In your host (physical) machine open Terminal and run
$ ssh <vmusername>@localhost -p 4242

Now you can control your virtual machine from the host terminal.

# Monitoring.sh
Creating the monitoring.sh file
## Preparation before running monitoring.sh
## Install net tools
sudo apt install net-tools

//     "workbench.editorAssociations": {
        "*.md": "default"
    },

## Create file
1. $ touch monitoring.sh
2. $ chmod +x monitoring.sh
3. $ nano monitoring.sh

```
arc=$(uname -a) The architecture of your operating system and its kernel version.
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
fdisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
udisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
pdisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvmt=$(lsblk | grep "lvm" | wc -l)
lvmu=$(if [ $lvmt -eq 0 ]; then echo no; else echo yes; fi)
#You need to install net tools for the next step [$ sudo apt install net-tools]
ctcp=$(cat /proc/net/sockstat{,6} | awk '$1 == "TCP:" {print $3}')
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | awk '$1 == "link/ether" {print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l) # journalctl should be running as sudo but our script is running as root so we don't need in sudo here
wall "
	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connexions TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd
" # broadcast our system information on all terminals
```  
## Cron
$ sudo crontab -e
Choosing nano as editor
```
@reboot /path/to/file/monitoring.sh
*/10 * * * * /path/to/file/monitoring.sh <every 10 min
```

## Signature
Get the signature and copy it into a txt file
Explication in the subject
Go to the folder where the VM is saved an run 
$ shasum yourfile.vdi
16b893f2bac0c52a851e483423ad7cc1983f82fa	

# Eval
(combination of Headlighter, [maresverbrugge](https://github.com/maresverbrugge/Born2beRoot-1/blob/main/eval_sheet_b2br.pdf) my own, wiki)

## General instructions
- signature.txt present
- check signature = .vdi (use diff)
- duplicate vm

## Project overview
### How does it works?
VM working through "Virtualization"/Emulation technology. Virtualization uses software to simulate virtual hardware that allows VMs to run on a single host machine.
### Why Debian?
It's easier to install and configure than CentOS (and i haven't use CentOS before)

### Differences between CentOS and Debian
// TODO
### What it's purpose?
VMs may be deployed to accommodate different levels of processing power needs, to run software that requires a different operating system, or to test applications in a safe, enclosed environment. 
### What is virtual machine?
In computing, a virtual machine (VM) is the virtualization/emulation of a computer system. Virtual machines are based on computer architectures and provide functionality of a physical computer. [read more](https://en.wikipedia.org/wiki/Virtual_machine)

### Diff between aptitude and apt?
Aptitude is a high-level package manager while APT is lower-level package manager which can be used by other higher-level package managers
[read more](https://www.tecmint.com/difference-between-apt-and-aptitude/)

### What is AppArmor?
AppArmor ("Application Armor") is a Linux kernel security module that allows the system administrator to restrict programs'
capabilities with per-program profiles.
[read more](https://en.wikipedia.org/wiki/AppArmor)

### Monitor.sh should be running every 10 min

## Simple setup

- No graphical interface
- Check password rules
  - // TODO
- Check UFW
  	$ sudo ufw status
- Check SSH
  	$ sudo service ssh status
- Check OS
  - // TODO
### What is SSH?
SSH, also known as Secure Shell or Secure Socket Shell, is a network protocol that gives users, particularly system 
administrators, a secure way to access a computer over an unsecured network.
[read more](https://searchsecurity.techtarget.com/definition/Secure-Shell)

## User

### My login
- part of user42
- part of sudo
- password policy
### Create a new user

	$ sudo adduser username                    <- creating new user (yes (no))  
	$ sudo chage -l username                   <- Verify password expire info for new user  
	$ sudo adduser username sudo                
	$ sudo adduser username user42             <- assign new user to sudo and user42 groups  


### How your script works?
... README.md

### Part two: What to check?   

   	$ lsblk                               <- Check partitions
	$ sudo aa-status                      <- AppArmor status
	$ getent group sudo                   <- sudo group users
	$ getent group user42                 <- user42 group users
	$ sudo service ssh status             <- ssh status
	$ sudo ufw status                     <- ufw status
	$ ssh username@ipadress -p 4242       <- connect to VM from your host (physical)$ machine via SSH
	$ nano /etc/sudoers.d/<filename>      <- yes, sudo config file. You can $ ls /etc/sudoers.d first
	$ nano /etc/login.defs                <- password expire policy
	$ nano /etc/pam.d/common-password     <- password policy
	$ sudo crontab -l                     <- cron schedule



I think this one need an addition to make it more easy to pass evaluation. So, here we are on our checklist and his commands.

How to change hostname?
[$sudo nano /etc/hostname]

Where is sudo logs in /var/log/sudo?
[$cd /var/log/sudo/00/00 && ls]
You will see a lot of directories with names like 01 2B 9S 4D etc. They contain the logs we need.
[$ sudo apt update]
[$ ls]
Now you see that we have a new directory here.
[$ cd <nameofnewdirectory> && ls]
[$ cat log] <- Input log
[$ cat ttyout] <- Output log

How to add and remove port 8080 in UFW?
[$ sudo ufw allow 8080] <- allow
[$ sudo ufw status] <- check
[$ sudo ufw deny 8080] <- deny (yes yes)

How to run script every 30 seconds?
[$ sudo crontab -e]
Remove or commit previous cron "schedule" and add next lines in crontab file
|*************************************************|
| */1 * * * * /path/to/monitoring.sh              |
| */1 * * * * sleep 30s && /path/to/monitoring.sh |
|*************************************************|
To stop script running on boot you just need to remove or commit
|********************************|
| @reboot /path/to/monitoring.sh |
|********************************|
line in crontab file.


# Other questions
$ head -n 2 /etc/os-release
$ /usr/sbin/aa-status
$ ss -tunlp
$ /usr/sbin/ufw status
