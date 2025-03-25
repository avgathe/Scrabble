package src.gameModel;

import java.util.HashMap;

public class AlphabetModel {
    private final int size;
    private HashMap<Lettre, Integer> alphabet = new HashMap<>(); // Alphabet contenant les pièces

    public  AlphabetModel() {
        this.size = 26;
        initAlphabetFrancais();
    }

    public void initAlphabetFrancais(){
        alphabet.clear();
        alphabet.put(new Lettre('a', 1), 9);
        alphabet.put(new Lettre('b',3), 2);
        alphabet.put(new Lettre('c',3), 2);
        alphabet.put(new Lettre('d',2), 3);
        alphabet.put(new Lettre('e',1), 15);
        alphabet.put(new Lettre('f',4), 2);
        alphabet.put(new Lettre('g',2), 2);
        alphabet.put(new Lettre('h',4), 2);
        alphabet.put(new Lettre('i',1), 8);
        alphabet.put(new Lettre('j',8), 1);
        alphabet.put(new Lettre('k',10), 1);
        alphabet.put(new Lettre('l',1), 5);
        alphabet.put(new Lettre('m', 2), 3);
        alphabet.put(new Lettre('n', 1), 6);
        alphabet.put(new Lettre('o', 1), 6);
        alphabet.put(new Lettre('p', 3), 2);
        alphabet.put(new Lettre('q', 8), 1);
        alphabet.put(new Lettre('r', 1), 6);
        alphabet.put(new Lettre('s', 1), 6);
        alphabet.put(new Lettre('t', 1), 6);
        alphabet.put(new Lettre('u', 1), 6);
        alphabet.put(new Lettre('v',4), 2);
        alphabet.put(new Lettre('w', 10), 1);
        alphabet.put(new Lettre('x', 10), 1);
        alphabet.put(new Lettre('y', 10), 1);
        alphabet.put(new Lettre('z', 10), 1);
    }

    public int getSizeAlphabet(){return this.size;}

    public HashMap<Lettre, Integer> getAlphabet() {
        return this.alphabet;
    }


}
