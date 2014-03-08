import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class FoxAndMountainRunner {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        int n = (Integer) reader.next(Integer.class);
        reader.next();
        
        String history = (String) reader.next(String.class);
        reader.close();

        FoxAndMountain solver = new FoxAndMountain();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.count(n, history));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }    
}
