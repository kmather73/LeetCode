import java.util.regex.Pattern;

public class Solution {
    public boolean isNumber(String s) {
        return Pattern.matches("[\\+-]?((\\d+(\\.\\d*)?)|(\\.\\d+))([Ee][\\+-]?\\d+)?",s.trim());
    }
}
