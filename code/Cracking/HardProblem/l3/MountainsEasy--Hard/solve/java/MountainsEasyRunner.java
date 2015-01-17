import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class MountainsEasyRunner {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<String> pictureBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] picture = new String[pictureBoxed.size()];
        for (int _i = 0; _i < pictureBoxed.size(); ++_i)
            picture[_i] = pictureBoxed.get(_i);
        reader.next();
        
        int N = (Integer) reader.next(Integer.class);
        reader.close();

        MountainsEasy solver = new MountainsEasy();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.countPlacements(picture, N));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }    
}
