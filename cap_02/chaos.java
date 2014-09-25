import java.io.*;
import java.util.*;

public class chaos {
	static double x1(double x0, double a) { return a*x0*(1-x0); }
	public static void main(String[] args) {
		String doc = "chaos.java\n";
		doc += "for jdk 1.7\n";
		doc += "\n";
		doc += "Usage: java chaos <X0> <A> <Iterations>\n";
		doc += "\n";
		doc += "Runs Xt+1 = A*Xt*(1-Xt) for each t in 0 ... Iterations, with Xt0 = X0\n";
		doc += "and prints the results to stdout.\n";
		doc += "\n";
		doc += "0 <= X <= 1\n";
		doc += "0 <= A <= 4\n";

		if (args.length < 3) {
			System.out.printf(doc);
			System.exit(0);
		}
		else {
			double x0 = Double.parseDouble(args[0]);
			double  a = Double.parseDouble(args[1]);
			long iters = Long.parseLong(args[2]);
			List<Double> history = new ArrayList<Double>();
			history.add(x0);
			
			double xn;
			for (int i = 0; i < iters; i++) {
				xn = x1(history.get(i), a);
				history.add(xn);
				System.out.printf("%3d %25.20f %35.20f x 10^10\n", i, history.get(i), history.get(i)*10000000000L);
			}
		}
	}
}
