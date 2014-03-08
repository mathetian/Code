import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class PolygonTraversal2Runner {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        int N = (Integer) reader.next(Integer.class);
        reader.next();
        
        List<Integer> pointsBoxed = (List<Integer>) reader.next(new TypeRef<List<Integer>>(){}.getType());
        int[] points = new int[pointsBoxed.size()];
        for (int _i = 0; _i < pointsBoxed.size(); ++_i)
            points[_i] = pointsBoxed.get(_i);
        reader.close();

        PolygonTraversal2 solver = new PolygonTraversal2();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.count(N, points));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }    
}
