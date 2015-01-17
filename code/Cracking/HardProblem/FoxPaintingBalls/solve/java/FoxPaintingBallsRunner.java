import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class FoxPaintingBallsRunner {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        long R = (Long) reader.next(Long.class);
        reader.next();
        
        long G = (Long) reader.next(Long.class);
        reader.next();
        
        long B = (Long) reader.next(Long.class);
        reader.next();
        
        int N = (Integer) reader.next(Integer.class);
        reader.close();

        FoxPaintingBalls solver = new FoxPaintingBalls();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.theMax(R, G, B, N));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }    
}
