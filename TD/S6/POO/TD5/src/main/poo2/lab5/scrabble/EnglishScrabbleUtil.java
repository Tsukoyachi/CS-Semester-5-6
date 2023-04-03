package main.poo2.lab5.scrabble;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.IntStream;
import java.util.stream.Stream;

import static java.util.stream.Collectors.counting;
import static java.util.stream.Collectors.groupingBy;

public class EnglishScrabbleUtil {
    static final int[] scrabbleENScore = { // a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
            1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    private static final int[] scrabbleENDistrib = { // a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
            9, 2, 2, 1, 12, 2, 3, 2, 9, 1, 1, 4, 2, 6, 8, 2, 1, 6, 4, 6, 4, 2, 2, 1, 2, 1};

    private final List<String> allowedWord;

    public EnglishScrabbleUtil() throws IOException {
        String fileName = "src/main/resources/ospd.txt";
        try (Stream<String> stream = Files.lines(Paths.get(fileName))) {
            allowedWord = stream.parallel().toList();
        }
    }

    public int distributionOfLetterInGame(char letter) {
        return scrabbleENDistrib[Character.toLowerCase(letter) - 'a'];
    }

    public int scoreOfLetterInGame(char letter){
        return scrabbleENScore[Character.toLowerCase(letter) - 'a'];
    }

    public boolean isWordAllowed(String word){
        return allowedWord.contains(word.trim().toLowerCase());
    }

    public boolean isWordAvailable(String word) {
        return word.chars()
                .filter(Character::isLetter)
                .mapToObj(c -> Character.toLowerCase((char) c))
                .collect(groupingBy(
                        Function.identity(),
                        counting()
                ))
                .entrySet().stream()
                .map(c -> distributionOfLetterInGame(c.getKey()) >= c.getValue())
                .filter(c -> !c)
                .toList().isEmpty();
    }

    public int computeScoreOfWord(String word){
        word = word.trim().toLowerCase();

        if(word.contains(" ")) {
            return 0;
        }
        return word.chars()
                .map(c -> scoreOfLetterInGame((char) c))
                .sum();
    }
}
