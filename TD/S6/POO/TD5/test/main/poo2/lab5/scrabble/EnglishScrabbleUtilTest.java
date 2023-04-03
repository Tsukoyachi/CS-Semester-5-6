package main.poo2.lab5.scrabble;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.IOException;

import static org.junit.jupiter.api.Assertions.*;

class EnglishScrabbleUtilTest {
    private EnglishScrabbleUtil englishScrabbleUtil;

    @BeforeEach
    void setup() throws IOException {
        englishScrabbleUtil = new EnglishScrabbleUtil();
    }
    @Test
    void test() {
        assertEquals(0, englishScrabbleUtil.computeScoreOfWord(""));
        assertEquals(0, englishScrabbleUtil.computeScoreOfWord(" "));
        assertEquals(8, englishScrabbleUtil.computeScoreOfWord("Hello"));
        assertEquals(29, englishScrabbleUtil.computeScoreOfWord("Buzzards"));
        assertEquals(87, englishScrabbleUtil.computeScoreOfWord("abcdefghijklmnopqrstuvwxyz"));

        assertTrue(englishScrabbleUtil.isWordAllowed("Hello"));
        assertTrue(englishScrabbleUtil.isWordAllowed("inspirit"));
        assertTrue(englishScrabbleUtil.isWordAllowed("Buzzards"));
        assertFalse(englishScrabbleUtil.isWordAllowed("abcdefghijklmnopqrstuvwxyz"));

        assertTrue(englishScrabbleUtil.isWordAvailable("abcdefghijklmnopqrstuvwxyz"));
        assertTrue(englishScrabbleUtil.isWordAvailable("hello"));
        assertFalse(englishScrabbleUtil.isWordAvailable("Buzzards"));
    }
}