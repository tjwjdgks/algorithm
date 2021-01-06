package com.company;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;

class Solution {

    public int solution(String[] lines) {
        int answer = 0;
        List<Long> checkPointList = new ArrayList<Long>();
        List<Log> logList = new ArrayList<Log>();

        for (String line : lines) {
            Log log = new Log(line);
            checkPointList.add(log.getStart());
            checkPointList.add(log.getEnd());
            logList.add(log);
        }

        Collections.sort(checkPointList);

        int top = 0;
        for(int i = 0; i < checkPointList.size(); i++) {
            int count = 0;
            for (Log log : logList) {
                if(log.isIn(checkPointList.get(i), checkPointList.get(i) + 999)) {
                    count++;
                }
            }

            if(count > top) {
                top = count;
            }
        }

        answer = top;
        return answer;
    }

    class Log {
        private long start = 0;
        private long duration = 0;
        private long end = 0;

        public Log(String line) {
            String[] split = line.split(" ");
            String dateString = split[0] + " " + split[1];
            try {
                Date startDate = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS").parse(dateString);
                this.end = startDate.getTime();

                String[] split2 = split[2].split("s");
                double parseDouble = Double.parseDouble(split2[0]);
                this.duration = (long) (parseDouble * 1000);

                this.start = this.end - this.duration;

            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        public boolean isIn(long checkPointStart, long checkPointEnd) {
            if(this.end < checkPointStart || this.start >= checkPointEnd) {
                return false;
            } else
                return true;
        }

        public long getStart() {
            return start;
        }

        public void setStart(long start) {
            this.start = start;
        }

        public long getDuration() {
            return duration;
        }

        public void setDuration(long duration) {
            this.duration = duration;
        }

        public long getEnd() {
            return end;
        }

        public void setEnd(long end) {
            this.end = end;
        }
    }
}public class Main {

    public static void main(String[] args) {
        Solution a = new Solution();
        int c = a.solution(new String[]{"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"});
        System.out.println(c);
    }
}
