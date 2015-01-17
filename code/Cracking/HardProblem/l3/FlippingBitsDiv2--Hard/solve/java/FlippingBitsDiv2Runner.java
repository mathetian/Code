import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class FlippingBitsDiv2Runner {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<String> SBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] S = new String[SBoxed.size()];
        for (int _i = 0; _i < SBoxed.size(); ++_i)
            S[_i] = SBoxed.get(_i);
        reader.next();
        
        int M = (Integer) reader.next(Integer.class);
        reader.close();

        FlippingBitsDiv2 solver = new FlippingBitsDiv2();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.getmin(S, M));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }    
}
