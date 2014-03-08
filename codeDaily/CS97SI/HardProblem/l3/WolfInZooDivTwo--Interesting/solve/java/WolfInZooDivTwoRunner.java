import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class WolfInZooDivTwoRunner {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        int N = (Integer) reader.next(Integer.class);
        reader.next();
        
        List<String> LBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] L = new String[LBoxed.size()];
        for (int _i = 0; _i < LBoxed.size(); ++_i)
            L[_i] = LBoxed.get(_i);
        reader.next();
        
        List<String> RBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] R = new String[RBoxed.size()];
        for (int _i = 0; _i < RBoxed.size(); ++_i)
            R[_i] = RBoxed.get(_i);
        reader.close();

        WolfInZooDivTwo solver = new WolfInZooDivTwo();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.count(N, L, R));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }    
}
