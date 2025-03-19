package src.gameModel;

public class PieceModel {

    private final char letter;
    private final int value;

    public PieceModel(char letter, int value) {
        this.letter = letter;
        this.value = value;
    }

    public boolean isInAlphabet(Alphabet alphabet) {
        return alphabet.getAlphabet().containsKey(this);
    }

    @Override
    public boolean equals(Object o) {
        if (o instanceof Letter l) {
            return l.getLetter() == this.letter;
        }
        return false;
    }

    @Override
    public int hashCode() {

        return 31 * Character.hashCode(this.letter);
    }

    @Override
    public String toString() {
        return String.valueOf(this.letter);
    }


    /**getter**/
    public char getLetter() {
        return letter;
    }

    public int getValue() {
        return value;
    }
}