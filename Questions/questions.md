- What is the purpose of a forward declaration?

Déclarer un type ou une fonction sans donner la déf complète. ça réduis les includes et les cyclic dependencies

- What are the differences between the stack and the heap?

La stack c'est gérée automatiquement, plus rapide mais limité en taille. 
La heap c'est gérée manuellement, plus lent et on peut facilement faire de la merde avec

- What is the difference between a variable passsed by copy, by reference or by pointer?

Copie : ça la duplique et ça affecte pas la var de base
Ref : ça affecte la var de base
Pointeur : En plus de pouvoir affecter la var de base, on peut faire pointer vers autre chose

- What is a pure virual class?

C'est une classe qui a au moins une fonction virtuelle pure (elle a pas d'implémentation). On peut pas l'instancier et elle sert a être hérité en polymorphe ou interface

- What are the different phases of the compilation process?

Preprocess : c'est les includes 
Compilation : ça transforme le code en assembleur
Linking : ça fait le .exe 

jsuis quasi sur d'en oublier une mais bon

- What is a smart-pointer? What problem do they solve? What problem do they bring?

ça gère la memoire d'un pointeur automatiquement, ça evite les fuites de memoire mais ça peut faire des cyclic dependencies 

- What is the problem that multi-threading try to solve?

Amélieorer les perfs de faisant plusieurs choses en meme temps en utilisant toute les ressources disponnibles

- Give at least two synchronization types that are used by multi-threading programs? What are their purpose?

Mutex : lock une ressource a un seul thread pour éviter les conflits et override
Semaphore : ça gere des ressources en limitant le nombre de threads qui peuvent y acceder

- What is a Spin Lock?

ça lock le thread en le faisant loop jusqu'a ce que la ressource soit dispo, busy wait

- What is a Dead Lock?

C'est quand deux threads sont lock sur des ressources que l'autre thread a besoin pour continuer, ça bloque tout le monde

- What does the following code display?
```cpp
int x = 10;
int* p = &x;
*p = 20;
std::cout << x << std::endl;
```

bah 20 


- What is the following code output?
```cpp
int* p = nullptr;
*p = 5;
std::cout << p << std::endl;
```
ça va crash parce que p pointe vers rien et on essaye de dereferencer


- What does the following code display?
```cpp
class A {
public:
    virtual void f() { std::cout << "A"; }
};

class B : public A {
public:
    void f() override { std::cout << "B"; }
};

A* obj = new B();
obj->f();
``` 

ça affiche B parce que c'est du polymorphisme, même si obj est de type A*, il pointe vers un objet de type B, donc la fonction f de B est appelée

- Does that code works?
```cpp
class A {
public:
    virtual void f() = 0
};

class B : public A {
public:
    void f() override { std::cout << "B"; }
};

A a;
a->f();

A* b = new B;
b->f();
```

Non parce que A c'est une classe abstraite donc on peut pas l'instancier ici `A a;`

- What is the number of loop that program will execute?
``` cpp
unsigned char nbHalfLoop = 200;
for (unsigned char id = 0; id < 2 * nbHalfLoop; id++)
{
cout << id;
}
```
Il veut faire 400 loops, mais je sais que un unsigned char ça va pas jusqu'a 400 par contre jsp combien précisement (j'ai envie de dire 128 mais je sais que je confonds)
Par contre si ça crash ou si ça loop a l'infini, aucune idée

- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data;

for (int i = 0; i < 100000; i++) {
    data.Add(i);
}

bool exists(int value) {
    for (int x : data) {
        if (x == value) return true;
    }
    return false;
}
```

un std::vector parce qu'il me semble que c'est le plus rapide ? (vraiement pas sur mdrr)


- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data = { 1, 2, 3, 4, 5 };

// ...

data.Insert(data.begin(), 0);
```

un std::deque pour insérer au début

- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data;

void add(int x) {
    for (int v : data) {
        if (v == x) return;
    }
    data.Add(x);
}
```

std::unordered_set pour pas avoir de doublons et enlever le check