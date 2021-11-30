arc=$(uname -a) # The architecture of your operating system and its kernel version.
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
fram=$(free -m | awk '$1 == "Mem:" {print $2}') # The amount of total memory in megabytes.
uram=$(free -m | awk '$1 == "Mem:" {print $3}') # The amount of used memory in megabytes.
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}') # The percentage of used memory.
fdisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}') # The total size of all filesystems in gigabytes.
udisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}') # The total size of all used filesystems in megabytes.
pdisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}') # The percentage of used filesystems.
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}') # The percentage of CPU usage.
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}') # The date and time of the last boot.
lvmt=$(lsblk | grep "lvm" | wc -l) # The number of LVM volumes.
lvmu=$(if [ $lvmt -eq 0 ]; then echo no; else echo yes; fi) # Whether the LVM is activated or not.
ctcp=$(cat /proc/net/sockstat{,6} | awk '$1 == "TCP:" {print $3}') # The number of TCP connections.
ulog=$(users | wc -w) # The number of users logged in.
ip=$(hostname -I) # The IP address of the host.
mac=$(ip link show | awk '$1 == "link/ether" {print $2}') # The MAC address of the host.
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l) # The number of commands executed by the sudo command.
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

#Architecture: Linux wil 4.19.0-16-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64 GNU/Linux
#CPU physical : 1
#vCPU : 1
#Memory Usage: 74/987MB (7.50%) 
#Disk Usage: 1009/2Gb (39%)
#CPU load: 6.7%
#Last boot: 2021-04-25 14:45
#LVM use: yes
#Connexions TCP : 1 ESTABLISHED
#User log: 1
#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
#Sudo : 42 cmd