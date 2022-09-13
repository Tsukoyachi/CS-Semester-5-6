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

> We have a chain of bits : 0110001110100101
> We apply a modulation to it to transfer a signal of our choice.
> To be able to apply a demodulation to it and obtain our chain of bits in the end.

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

> **All the previous note were about the transfer of bits (0 or 1), that was the first layer of the OSI/ISO model. But transfering bits isn't enough.** 

---
#### Data Communication Management : 

Challenges of the second layer :
	- How to distinguish consecutives frames
	- Shared medium between various connected devices
	- Who sent the frame

Personnal note to sum up :
- The challenge of the first layer was to transfer bits.
- The challenge of the second layer is to transfer layer (trains de bits in french).

---

#### Distinguish consecutives frames :

(à rattraper...)

---

#### Shared medium between various connected devices :

>CSMA stands for Carrier Sense Multiple Access. It is a set of protocols for accessing a medium. These check that the medium is available before starting to send a frame. They also detect or avoid message collisions in transmissions.

- CSMA/CD (Ethernet) -> Collision Detection
- CSMA/CR (CAN) -> Collision resolution
- CSMA/CA (Wifi) -> Collision Avoidance
- Different kinds of strategies

A system must be able to detect at wich moment he receives multiple thing at once.

##### Collision Detection :

The first machine to "talk" is the machine who detect the collision.
Then all the machine stop "talking".
Every machine who want to communicate choose a number between 1 and 7, it's the number of period they wait before "talking". The probability of having two machines who talk at the same time is really low.

>In a group of person, everyone can talk when they want to (after a silence), and if two people try to speak at the same time they stop and wait a short time (random for )

##### Collision Resolution :

When we have conflict, we check if it's the same level.
And when a machine send a signal who is different from the other he's stopped by the bus to let the other "talk".

>In a group of person, if two people talk at the same time, they keep talking while they say the same thing. And when they don't say the same thing, a logic arbitration is done and one of them stop talking.



