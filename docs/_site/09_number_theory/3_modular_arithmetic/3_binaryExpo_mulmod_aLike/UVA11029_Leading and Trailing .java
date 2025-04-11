import java.math.BigInteger;
import java.util.Scanner;

//optimise solution
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            BigInteger n = sc.nextBigInteger();
            BigInteger k = sc.nextBigInteger();

            // Calculate last three digits using modular arithmetic
            BigInteger mod = BigInteger.valueOf(1000);
            BigInteger lastThree = n.modPow(k, mod);

            // Calculate first three digits
            double logValue = k.doubleValue() * Math.log10(n.doubleValue());
            double fractionalPart = logValue - Math.floor(logValue);
            int firstThree = (int) (Math.pow(10, fractionalPart) * 100);

            // Format the output
            System.out.printf("%03d...%03d\n", firstThree, lastThree.intValue());
        }
        sc.close();
    }
}

//using binary expo
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            BigInteger n = sc.nextBigInteger();
            BigInteger k = sc.nextBigInteger();

            // Calculate last three digits using modular arithmetic
            BigInteger mod = BigInteger.valueOf(1000);
            BigInteger lastThree = n.modPow(k, mod);

            // Calculate first three digits using binary exponentiation
            double base = n.doubleValue();
            double leadingDigits = 1.0;
            BigInteger exp = k;
            BigInteger two = BigInteger.valueOf(2); // Use BigInteger.valueOf(2)

            while (exp.compareTo(BigInteger.ZERO) > 0) {
                if (exp.mod(two).equals(BigInteger.ONE)) { // Check if exp is odd
                    leadingDigits *= base;
                    while (leadingDigits >= 1000) {
                        leadingDigits /= 10; // Truncate to leading digits
                    }
                }
                base *= base;
                while (base >= 1000) {
                    base /= 10; // Truncate to leading digits
                }
                exp = exp.divide(two); // Divide exp by 2
            }
            int firstThree = (int) leadingDigits;

            // Format the output
            System.out.printf("%03d...%03d\n", firstThree, lastThree.intValue());
        }
        sc.close();
    }
}
