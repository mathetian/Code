import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class ThreeColorabilityEasyRunner {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<String> cellsBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] cells = new String[cellsBoxed.size()];
        for (int _i = 0; _i < cellsBoxed.size(); ++_i)
            cells[_i] = cellsBoxed.get(_i);
        reader.close();

        ThreeColorabilityEasy solver = new ThreeColorabilityEasy();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.isColorable(cells));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }    
}
