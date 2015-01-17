import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class HyperKnightRunner {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        int a = (Integer) reader.next(Integer.class);
        reader.next();
        
        int b = (Integer) reader.next(Integer.class);
        reader.next();
        
        int numRows = (Integer) reader.next(Integer.class);
        reader.next();
        
        int numColumns = (Integer) reader.next(Integer.class);
        reader.next();
        
        int k = (Integer) reader.next(Integer.class);
        reader.close();

        HyperKnight solver = new HyperKnight();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.countCells(a, b, numRows, numColumns, k));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }    
}
