
public class FunctionDevelopment {
	public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        int[] p_array= new int[progresses.length];
        int[] s_array=new int[speeds.length];
        for(int i=0;i<progresses.length;i++){
            p_array[i]=100-progresses[i];
        }
        int j;
        for(int i=0;i<speeds.length;i++){
            for(j=0;;){
                if(p_array[i]<=speeds[i]*j) break;
                j++;
            }
            s_array[i]=j;
        }
        for(int i=0;i<s_array.length-1;i++){
            if(s_array[i]>s_array[i+1]) s_array[i+1]=s_array[i];
        }
        int first=s_array[0];
        int count[]=new int[1000];
        int count_day=1;
        for(int i=0;i<s_array.length;i++){
            if(first==s_array[i]) count[count_day-1]++;
            else{
                first=s_array[i];
                count_day++;
                count[count_day-1]++;
            }
        }
        answer=new int[count_day];
        for(int i=0;i<count_day;i++){
            answer[i]=count[i];
        }

        return answer;
    }
}
/*
Programmers Skill Check Level2
Compute how many days needed to complete progresses
if preceded progresses haven't done, following progresses completed after then.
if the number of days needed to complete progresses are same, count it
*/