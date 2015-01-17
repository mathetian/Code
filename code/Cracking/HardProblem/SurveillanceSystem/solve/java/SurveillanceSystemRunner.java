import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class SurveillanceSystemRunner {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        String containers = (String) reader.next(String.class);
        reader.next();
        
        List<Integer> reportsBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] reports = new int[reportsBoxed.size()];
        for (int _i = 0; _i < reportsBoxed.size(); ++_i)
            reports[_i] = reportsBoxed.get(_i);
        reader.next();
        
        int L = (Integer) reader.next(Integer.class);
        reader.close();

        SurveillanceSystem solver = new SurveillanceSystem();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.getContainerInfo(containers, reports, L));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }    
}
