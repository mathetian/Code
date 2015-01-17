import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class BallsSeparatingRunner {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<Integer> redBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] red = new int[redBoxed.size()];
        for (int _i = 0; _i < redBoxed.size(); ++_i)
            red[_i] = redBoxed.get(_i);
        reader.next();
        
        List<Integer> greenBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] green = new int[greenBoxed.size()];
        for (int _i = 0; _i < greenBoxed.size(); ++_i)
            green[_i] = greenBoxed.get(_i);
        reader.next();
        
        List<Integer> blueBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] blue = new int[blueBoxed.size()];
        for (int _i = 0; _i < blueBoxed.size(); ++_i)
            blue[_i] = blueBoxed.get(_i);
        reader.close();

        BallsSeparating solver = new BallsSeparating();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.minOperations(red, green, blue));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }    
}
