# mygrep

MyGrep-ohjelma on yksinkertaistettu versio Linuxin grep-komennosta. Se etsii annettua hakutermiä tekstitiedostosta tai merkkijonosta ja tulostaa vastaavat tai ei-vastaavat rivit.

![MyGrep](/images/mygrep.png)
Kuva 1. Esimerkki ohjelman suorituksesta

## Ohjelman toiminta

Ohjelma on tehty C++-ohjelmointikielellä ja sen lähdekoodi on jaettu eri tiedos-toihin. Ohjelman suoritus alkaa main.cpp-tiedostosta, joka kutsuu App-luokan run-funktiota. Tälle funktiolle annetaan ohjelman käynnistyksen yhteydessä annetut komentoriviargumentit. Kuten kuvasta 1 näkee, ohjelman toimintatila määräytyy annettujen argumenttien lukumäärän (argc) perusteella:

![run-function](/images/app-run-funktion.png)
Kuva 2. App-luokan run-funktio

Kun oikea toimintatila on valittu, ohjelman suoritus siirtyy MyGrep-luokalle. Interaktiivisessa tilassa MyGrep-luokka palauttaa haetun merkkijonon esiintymiskohdan, ja tiedostohakutilassa se palauttaa hakuehdot täyttävät tekstirivit. Lopuksi App-luokka tulostaa tulokset.

## Ohjelman eri tilat ja suoritustavat

### Interaktiivinen tila

Kun ohjelma käynnistetään ilman argumentteja, se pyytää käyttäjää syöttämään merkkijonon ja hakutermin, jonka jälkeen se ilmoittaa, löytyikö hakutermi ja mistä kohdasta.

### Tiedostohakutila

Kun ohjelmalle annetaan argumentteina hakutermi ja tiedostonnimi, ohjelma etsii tiedostosta hakutermiä vastaavat rivit.

### Tiedostohakutila valinnaisilla argumenteilla

Hakua on mahdollista tarkentaa valinnaisilla argumenteilla antamalla ne ennen hakutermiä ja tiedostonnimeä.

### Ohjelman suoritustavat

Ohjelmaa voidaan suorittaa komentoriviltä seuraavilla tavoilla:

```bash
# Interaktiivinen tila
./mygrep.exe

# Tiedostohakutila
./mygrep.exe <hakutermi> <tiedosto>

# Tiedostohakutila valinnaisilla argumenteilla
./mygrep.exe -o<komento> <hakutermi> <tiedosto>
```

### Saatavilla olevat valinnaiset argumentit

| Argumentti | Selitys                                                                  |
| ---------- | ------------------------------------------------------------------------ |
| `-l`       | Näyttää rivinumerot                                                      |
| `-o`       | Näyttää moneltako riviltä hakutermi löytyi                               |
| `-i`       | Ohjelma ei välitä isoista ja pienistä kirjaimista                        |
| `-r`       | Käänteinen haku – tulostaa vain rivit, joilla ei ole annettua hakutermiä |

## Tietoa luokista

### App-luokka

`App`-luokka huolehtii ohjelman suorituksesta ja valitsee oikean suoritustavan annettujen argumenttien perusteella. Suorituksen lopuksi se näyttää hakutulokset.

### MyGrep-luokka

`MyGrep`-luokka vastaa tiedostojen lukemisesta ja hakutermin etsimisestä tekstistä. Luokka sisältää kaksi eri funktiota:

#### find_from_string

Funktio hyödyntää `std::string`-luokan omaa `find`-funktiota, joka palauttaa ensimmäisen esiintymän aloitusindeksin merkkijonossa. Mikäli haettavaa hakutermiä ei löydy, funktio palauttaa arvon `std::string::npos`.

#### get_matching_lines

Funktio palauttaa tiedostossa olevat hakuehtoja täyttävät rivit. Jos tiedoston avaaminen epäonnistuu, funktio heittää `std::runtime_error`-poikkeuksen.

### Optiot

Komentoriviltä annettavien valinnaisten hakuasetusten (optioiden) tallentamiseen käytetään `Options`-tietorakennetta. Tämä pitää koodin rakenteen siistinä ja tekee valittujen asetusten lukemisesta haun aikana helppoa.

![Options struct](/images/options-struct.png)

_Kuva 3. Kuva Options-tietorakenteesta._
