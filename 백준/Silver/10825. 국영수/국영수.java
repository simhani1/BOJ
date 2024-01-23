import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<Student> studentList = new ArrayList<>();
        N = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            studentList.add(new Student(st.nextToken(), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        studentList.sort(new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                if (o1.math == o2.math && o1.english == o2.english && o1.korean == o2.korean) {
                    return o1.name.compareTo(o2.name);
                } else if (o1.korean == o2.korean && o1.english == o2.english) {
                    return Integer.compare(o1.math, o2.math) * -1;
                } else if (o1.korean == o2.korean) {
                    return Integer.compare(o1.english, o2.english);
                }
                return Integer.compare(o1.korean, o2.korean) * -1;
            }
        });
        for (Student s : studentList) {
            System.out.println(s.name);
        }
    }
}

class Student {
    String name;
    int korean;
    int english;
    int math;

    public Student(String name, int korean, int english, int math) {
        this.name = name;
        this.korean = korean;
        this.english = english;
        this.math = math;
    }

}