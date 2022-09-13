# Network, Internet, Web and Services
---
### Lessons date :
- 13/09/22

### Teachers :
- Jean-Yves Tigli
- Yves Roudier

### Tags :
#Réseaux, #Network, #Harmonisation

---

#### Analog Communication

![[Pasted image 20220913093145.png | 350 | center]]

> The Sender send a signal by using a Transmission medium to the Receiver.
> 
> It can be send wwith a cable, for exemple phone communication, or morse code I reckon.
> - medium : copper cable
> - analog signal

---

#### So Telecommunications are...

- Telecommunications
	- The electronic transmission of signal for communication, including such means as :
		- Radio
		- Telephone
		- Television

---

#### Data communications

A specialized subset of telecommunications that refers to the electronic collection, processing, and distribution of data -- typically between computer system hardware devices.

> We have a chain of bytes : 0110001110100101
> We apply a modulation to it to transfer a signal of our choice.
> To be able to apply a demodulation to it and obtain our chain of bytes in the end.

---

#### Device : Modem

##### Modem : 
>Modulate a digital signal into an analog signal for transmission via analog medium, then demodulates the signal into digital for receiving.

---

#### Example of Type Modulation Techniques :

- **Amplitude modulation :** A classic analog signal who transfer data by changing his amplitude.
- **Frequency modulation :** Same thing but instead of changing his amplitude, he changes his frequency.

---


#### Medium Electromagnetic Spectrum :

- Frequencies are more of less well-caried according to the medium type.

---

> **All the previous note were about the transfer of bytes (0 or 1), that was the first layer of the OSI/ISO model. But transfering bits isn't enough.** 

---
#### Data Communication Management : 

Challenges of the second layer :
	- How to distinguish consecutives frames
	- Shared medium between various connected devices
	- Who sent the frame

Personnal note to sum up :
- The challenge of the first layer was to transfer bits.
- The challenge of the second layer is to transfer layer (trains de bits in french).

##### Distinguish consecutives frames :

(à rattraper...)

---

##### Shared medium between various connected devices :

>CSMA stands for Carrier Sense Multiple Access. It is a set of protocols for accessing a medium. These check that the medium is available before starting to send a frame. They also detect or avoid message collisions in transmissions.

- CSMA/CD (Ethernet) -> Collision Detection
- CSMA/CR (CAN) -> Collision resolution
- CSMA/CA (Wifi) -> Collision Avoidance
- Different kinds of strategies

A system must be able to detect at wich moment he receives multiple thing at once.

###### Collision Detection :

The first machine to "talk" is the machine who detect the collision.
Then all the machine stop "talking".
Every machine who want to communicate choose a number between 1 and 7, it's the number of period they wait before "talking". The probability of having two machines who talk at the same time is really low.

>In a group of person, everyone can talk when they want to (after a silence), and if two people try to speak at the same time they stop and wait a short time (random for each person).

###### Collision Resolution :

When we have conflict, we check if it's the same level.
And when a machine send a signal who is different from the other he's stopped by the bus to let the other "talk".

>In a group of person, if two people talk at the same time, they keep talking while they say the same thing. And when they don't say the same thing, a logic arbitration is done and one of them stop talking.




##### Who sent the frame :

(à rattraper j'ai raté un slide...)

###### MAC Address (IEEE 802.1) :
- For
	- Local Area Network (LAN, ex : Ethernet)
	- Wireless Local Area Network (WLAN, ex : Wifi, Lifi)
	- Personnal Area Network (PAN, ex : Bluetooth)
	- Low Power Wide Area Network (LPWAN, ex : LoRa, Sigfox, Zigbee)
- See ifconfig / ipconfig commands

#### LAN Devices :
- Switch
- Wifi hostspot
- Bluetooth hotspot
- Lifi hotspot

##### Ethernet and Switch devices :

###### Switch :
Switches have a max bandwitdth or a speed in bytes

##### Ethernet :
Ethernet plug.
Plug must be compatible with cables.
#### Third layer in OSI/ISO model, Internet !

From a network, to another.
>Internet is the interconnexion of every network and it can't be different because every local network have his own constraint.

Gateway : It's a device that link two network who present a different topology.

Router : He receive a frame, and redirect it to the sender identified by his IP adress.

##### IP Datagram :
![[Pasted image 20220913110148.png | center | 700]]

Fields :
- TTL (Time to live) : 
	- It's a number, who decrement each time he pass a router.
	- If he reaches 0, the router send a packet to himself and then tell the sender he failed to send the data.

##### IPV4 Address Formats

![[Pasted image 20220913111035.png | center | 600]]

- 32 bytes global Internet address
- Network part and host part

###### Network Masks
- Distinguishes wich portion of the address identifies the network and wich portion of the address identifies the node.
- Default mask :
	- Class A : 255.0.0.0
	- Class B : 255.255.0.0
	- Class C : 255.255.255.0
- Example :
	- IP = 172.22.176.1
	- Masque de sous réseau : 255.255.240.0

##### Netid, Hostid, Mask

![[Pasted image 20220913111948.png | center | 600]]

##### Commands 
- nslookup
- tracert
- route : allow the user to have the route table of the computer.

Traject data :
 > We send the data to the router, we know the router adress with the cmd command 'route PRINT' I think, and then we need to know the mac adress of the router. The router will check the interface he need to send the data to and will create the frame with his route table.
 
##### Help to associate names and IP adresses

>Domain name server : DNS

![[Pasted image 20220913114237.png | center | 600]]

