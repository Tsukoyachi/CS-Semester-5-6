## Exercice 1 :

Ici aucun code n'est à faire, il suffit de compiler le java avec -h afin d'en générer l'interface des méthodes natives à faire en c.

Et de créer une librairie dynamique à partir de l'implémentation en c de l'interface faite précédemment.

Ici le makefile possède déjà tout ce qu'il faut :

```makefile
#---------------------------------------------------------------------------------
# Variables
#---------------------------------------------------------------------------------

JAVA_H=/usr/lib/jvm/java-17-openjdk-amd64

# Compilateur et options
# ----------------------

CC=g++
CXXFLAGS=-fpic -Wall -I$(JAVA_H)/include/ -I$(JAVA_H)/include/linux

TARGET=libHelloWorld.so
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
H_FILE=$(SRC:.cpp=.h)

#---------------------------------------------------------------------------------
# Cibles
#---------------------------------------------------------------------------------
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -Wl,-soname,$@ -shared -o $@ $< 

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(TARGET) $(OBJ) \#* *~

```

Pour pouvoir exécuter le java, étant sous linux il me faut également modifier le LD_LIBRARY_PATH pour pouvoir trouver la bibliothèque, comme ceci :
`export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH`

## Exercice 2 :

Ici, il ne suffit que de lancer l'exécution du java compilé précédemment.

![[Pasted image 20230502093629.png | center]]

## Exercice 3 :

On rajoute la déclaration des méthodes natives dans le java ainsi qu'une utilisation simple de ses 2 méthodes.
```java
public static native void printStringToCpp(String str);  
public static native String stringFromCpp();
```

On compile avec le -h pour générer l'interface et on copie l'implémentation cpp du prof à rajouter dans notre implémentation déjà existante.

On se heurte cependant à une erreur, dans l'implémentation de stringFromCpp l'un des paramètres était jobject obj, cependant celui-ci n'est utile que lorsque la méthode java n'est pas static, ce qui ne nous intéresse pas vraiment ici. On le remplace donc par un jclass cl pour la rendre static.

Après cela tout fonctionne.

## Exercice 4 :

Ici on a d'abord besoin de repasser la méthode printStringToCpp en méthode de classe car l'objectif est d'appeler une méthode de classe dans du code cpp.

On retire donc le static en java et on remet jobject obj à la place de jclass cl.

Ensuite dans le code cpp au lieu d'appeler la méthode test nous appellerons la méthode printStringToCpp. Et nous déclarerons la méthode native, non static et void callVoidMethod en Java. Nous l'appellerons en suite tout simplement afin de vérifier son bon fonctionnement.

Après cela tout fonctionne.

## Exercice 5 :

Ici on déclare la méthode native, non static, qui renvoie un String toString en Java. Ensuite on ajoute son implémentation en C avec un appel simple en Java.

L'api JNI est assez simple en ce qui concerne l'accès à des variables d'un objet.
- On instancie le jfieldId que l'on va utiliser ensuite
- On pourra ainsi Get/Set le field à l'aide de l'environnement, de l'id et de la valeur si on set.

## Exercice 6 :

Ici on ajoute une méthode en java qui sera implémentée en c, cette méthode appelera notre méthode c qui calcul fibonacci. On l'appelle ensuite en c.

Le résultat correspond à nos attentes.

## Exercice 7 :

```java
import java.lang.management.ManagementFactory;
import java.lang.management.RuntimeMXBean;

public class exo1 {
    static {
    }

    public static void main(String args[]) {
        //First Method
        RuntimeMXBean runtimeBean = ManagementFactory.getRuntimeMXBean();
        String jvmName = runtimeBean.getName();
        long pid1 = Long.valueOf(jvmName.split("@")[0]);
        System.out.println("First method PID : "+pid1);
        //Second Method
        long pid2 = ProcessHandle.current().pid();
        System.out.println("Second method PID : "+pid2);
    }
}
```

Voici les deux méthodes disponible en Java avant et après Java 9 