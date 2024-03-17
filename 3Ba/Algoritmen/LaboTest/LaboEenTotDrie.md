# Algoritmen Labo Eén - Drie

## Algemeen

* Waar mogelijk hulpfuncties gebruiken
    * Vb: build-functie, geef diepte mee indien noodzakelijk
    * ```cpp
        void KdTree::build(std::vector<Color> &colors) {
            // TODO
            root = new KdNode();
            build(colors,root,0);
        }

        void KdTree::build(std::vector<Color> &colors, KdNode* &node, int depth) {
            node->left = new KdNode();
            node->right = new KdNode();

            node->splitDim = getDimWithMaxRange(colors);
            node->value = getMedian(colors,node->splitDim);

            std::vector<Color> colorsLeft, colorsRight;

            for (Color& c: colors) {
                if (Color::compare(c,node->splitDim,node->value) < 0) {
                    colorsLeft.push_back(c);
                } else {
                    colorsRight.push_back(c);
                }
            }

            if ((depth + 1) < maxDepth) {
                if (colorsLeft.size() > 0) {
                    build(colorsLeft,node->left,depth+1);
                }
                if (colorsRight.size() > 0) {
                    build(colorsRight,node->right,depth+1);
                }
            } else {
                node->left->color = Color::getAverage(colorsLeft);
                node->right->color = Color::getAverage(colorsRight);
            }
        }
    * Recursief is niet altijd de meest efficiënte optie, maar in sommige gevallen wel de snelste manier om het degelijk te programmeren
        * Gevallen waarbij recursie kan helpen: bouwen van een multidimensionele boom zoals een KdTree, bepalen van de hoogte van een boom (elk kind zijn hoogte doen bepalen en optellen), query van een IntervalTree
        * Gevallen waarbij best iteratief gewerkt kan worden: RedBlack-tree of IntervalTree insert

* Operator overloading niet vergeten
    * Voorbeeld: 
    * ```cpp 
        bool operator<(const Interval &interval) {
            return this->begin < interval.begin;
        }

        bool operator>(const Interval &interval) {
            return this->begin > interval.begin;
        }

        bool operator==(const Interval &interval) {
            return this->begin == interval.begin && this->end == interval.end;
        }
        // in dit geval is het vergelijken van intervallen, maar kan ook over andere dingen gaan

## RedBlackTree

### Insert

* Eerst plaats bepalen waar een insert zal plaatsvinden, beginnende vanaf de root
* De Node in het begin aanmaken + ouder bijhouden

### Rotaties

* Kopie bijhouden van de te roteren knoop
* Niet vergeten de pointer naar de ouderknoop aan te passen (en omgekeerd)
* Niet vergeten de RedBlack Properties te herstellen

### RedBlack Properties

* Goed voorwaarden bekijken en eens op papier uittekenen

## IntervalTree

### Insert

* Niet vergeten om de variabele maxEndPoint aan te passen

## KdTree

### Build (met ColorQuantization)

* Kindbomen aanmaken
* Dimensie om op te splitsen bepalen
  * Door middel van een std::transform een bepaalde kleur uitfilteren
  * Door middel van std::minmax_element de minimum en maximum elementen bepalen en zo de maxRange bepalen door max - min te doen
  * Value wordt de mediaan, dus met std::nth_element sorteren
  * Kleuren sorteren op basis van kleiner of groter dan de mediaan
  * Zolang de maxdiepte-1 niet bereikt is, subbomen bouwen
  * Als maxdiepte-1 bereikt is, kan de kleur van een *leaf* bepaald worden

### Quantize

* Boompje bouwen
* Door middel van std::transform & query in de boom elke kleur/pixel vervangen

### Query

* Zolang het linkerkind niet null is en de kleur kleiner in waarde is dan de value, zoek verder in linkerkind
* Zolang het rechterkind niet null is en de kleur groter in waarde is dan de value, zoek verder in rechterkind
* Zodra er geen kinderen meer zijn, kleurtje teruggeven