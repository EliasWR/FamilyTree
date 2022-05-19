# Feedback

## README.md

Dere har en README. Per nå så er det mer som en arbeidslogg. I endelig innlevering ønsker jeg å se en kort beskrivelse av innholdet i prosjektet samt UML diagram.

## Git

I `.gitignore` kan dere egentlig fjerne linje 1-32 (vertfall i dette prosjektet), og erstatte `cmake-build-debug` med `cmake-build*`. 
Stjernen er wildcard og vil matche alt etter den. Dette gjør at e.g., `cmake-build-release` også vil eksluderes. 

## CMake

Ser gjerne at dere gjør det samme for `add_executable(FamilyTree ... )` som for testene. Dvs. lag en egen folder `tool` eller lignende med tilsvarende CMake oppsett.

Fjern `include_directories(.)`. Uansett, så skal `include_directories` peke på, i deres tilfelle, `${CMAKE_SOURCE_DIR}/include"`. Dette gjør at dere kan include kode ved bruk av `#include "Node.h"`, ikke `#include "include/Node.h"`.


`include_directories("${CMAKE_SOURCE_DIR}/Include")` -> liten forbokstav på include. 

Vurder `target_include_directories` for hver target istedenfor `include_directories`.

`.cpp` filer hører ikke hjemme i `include`, som kun er for public headere. Putt i en folder `src` og definer et bibliotek ved bruk av `add_library`. Det linker da til dette biblioteket når dere kjører `add_executable` andre steder.

## Kode

Prosjektet har ikke en definert formaterings stil (e.g., `.clang-format`). Hva skjer om noen andre jobber på koden og kjører formatering?

Prøv å rename headerene deres fra `.h` (typisk C) til `.hpp` (typisk C++). CLion har en option for å gjøre dette default en plass.

Her menes .clang-format
reformat code cmd + shift + f

### Person.h

`std::array<int,3> _birth{};` -> Veldig lite OOP. Lag en egen klasse for dette.
`char _gender;` -> Vurder enum.


```cpp
void setFirstName (std::string firstName) {
    _firstName = firstName;
}
```
Vurder const reference eller `std::move` for å unngå en enkstra kopi i setterene.

```cpp
 void setGender (char sex) {
    _gender = sex;
}
```
Ingenting som stopper invalid input her. 


`void writePerson (XmlWriter &write)` -> Vurder å flytte logikken ut i en egen klasse. Her har dere også mulighet til å introdusere arv. Kan vi lage et generisk grensesnitt for å lese/skive personer fra fil med implementasjon for XML, JSON, etc. ? 

#### Node.h

Her har dere implementert et generisk tre som kan gjenbrukes til ulike formål. E.g., et familetre. 

```cpp
// Constructor taking person.
// Creating person objects with unique ownership in the node.
```

Stemmer dette?

`std::shared_ptr<T> _person;` -> Trenger denne egentlig å være allokert på heapen? Gi nytt navn til variabelen. Noden deres bruker template, men koden tilsier at den holder typen person (`_person`). I realiteten kan det være hva som helst. Bruk generisk `value` eller `data` etc..

```cpp
bool hasChild() {
    return _parent != nullptr;
}
```
Dere mener `hasParent`? Spørst om dere bruker omvendt terminologi for å få det til å matche logisk med en famile. 
Metoden kan (alt som kan bør) være `const`.

`traverseUpwardsFirst` -> Rename til `traverseUpwards`. First tilsier at den gjør mer enn å bare gå oppover. 

```cpp
void add(Node &f) {
    f._parent = this; // this -> parent node*
    _children.emplace_back(&f);
}
```

Kunne man tenke seg at man la til en `person` og ikke en `node` her? Da får klassen `Node` full kontroll på hvordan nodene blir laget. Den eneste noden man da trenger å konstruere utenfor klassen er når man skal opprette rot noden.

### LinkedList.h

Om denne ikke brukes, så fjern fra prosjektet. Se også kommentar for `Menu.h`

### Filehandling.h/cpp

Dette er kode funnet på nett? Forventer da en referanse.

```cpp
#include "Person.h"
#include "Node.h"
#include "LinkedList.h"
```

Fjern. Disse blir ikke brukt.

```cpp
#include <iostream>
```

Denne brukes ikke i headeren. Flytt til .cpp. Litt av poenget med å splitte koden er å skjule implementajonen slik at headere kun brukt i kildefilen ikke lekker ut. De som inkluderer `FileHandling.h` får også `<iostream>` med på kjøpet, selv om det ikke er nødvendig.

### Familiy_Tree.cpp

Work in progress ser jeg. XML koden hører hjemme i en test.
Fjern bubbleSort, med mindre dere har tenkt å bruke den. Viktig at dere skjønner hva `std::swap` gjør her.

### Menu.h

Denne filen trenger bedre dokumentasjon på hva formålet med de ulike funksjonene er.

`<stdio.h>` -> C header. Alle(?) slike (standard) C headere har en C++ versjon. I dette tilfellet `<cstdio>`.  

```cpp
char c, m, f, o;
m = 'm';
f = 'f';
o = 'o';
```

Gjør heller:

```cpp
char m = 'm';
char f = 'f';
char o = 'o';
```

eller: `while ((c != 'm') && (c != 'f') && (c != 'o'))`

Jeg er litt usikker på formålet til `linked_list` i koden din og har ikke anledning til å gå dypere. Husk at du har en tre datastruktur, og denne kan brukes i sin helhet til å løse oppgaven.

## Unit testing

Dere har fått opp basis oppsett for testing, men mangler faktiske tester. Start med det enkleste (basis funksjonalitet) og jobb dere oppover.

## Continuous integration (CI)

Dere har fått med CI. Bra. 
Legg gjerne til macos runner.
`config.yml` har dere hentet fra GitHub. YAML støtter kommentarer, så ta med referanse her.
For deres egen del, så er det viktig at dere skjønner hva som skjer og hvorfor det fungerer. CI er alfa og omega i moderne programutvikling.

---

Disclaimer: Tilbakemeldingen er ikke nødvendigvis komplett og kan ikke brukes som fasit. Bruk skjønn.
