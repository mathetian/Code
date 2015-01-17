import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class KnightCircuitRunner {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        int w = (Integer) reader.next(Integer.class);
        reader.next();
        
        int h = (Integer) reader.next(Integer.class);
        reader.next();
        
        int a = (Integer) reader.next(Integer.class);
        reader.next();
        
        int b = (Integer) reader.next(Integer.class);
        reader.close();

        KnightCircuit solver = new KnightCircuit();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.maxSize(w, h, a, b));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }    
}
