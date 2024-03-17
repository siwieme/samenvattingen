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
        * Gevallen waarbij recursie kan helpen: bouwen van een multidimensionele boom zoals een KdTree, bepalen van de hoogte van een boom (elk kind zijn hoogte doen bepalen en optellen)
        * Gevallen waarbij best iteratief gewerkt kan worden: RedBlack-tree of IntervalTree insert

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