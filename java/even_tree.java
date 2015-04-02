import java.util.Scanner;
import java.util.Arrays;

public class even_tree {

        /**
         * @param args
         */

        public static void main(String[] args) {
                // TODO Auto-generated method stub

                int tree[];
                int count[];

                Scanner scan = new Scanner(System.in);

                int N = scan.nextInt(); //points
                int M = scan.nextInt();

                tree = new int[N];
                count = new int[N];
                Arrays.fill(count, 1);

                for(int i=0;i<M;i++)
                {
                    int u1 = scan.nextInt();
                    int v1 = scan.nextInt();
                    System.out.println("u1: " + u1);
                    System.out.println("v1: " + v1);
                    tree[u1-1] = v1;
                    count[v1-1] += count[u1-1];
                    System.out.println("Count: " + count[v1-1]);
                    int root = tree[v1-1];
                    
                    while(root!=0)
                    {
						System.out.println("Root: " + root);
                        count[root-1] += count[u1-1];
                        root = tree[root-1];
                    }
                }

                System.out.println("");

            int counter = -1;
                for(int i=0;i<count.length;i++)
                {
                        if(count[i]%2==0)
                        {
                                counter++;
                        }

                }
                System.out.println(counter);

        }

}
