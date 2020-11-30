import java.io.IOException;
import java.util.Iterator;

import org.apache.hadoop.io.*;
import org.apache.hadoop.mapred.*;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.util.*;

public class maxTemp{

public static class MaxMapper extends MapReduceBase implements Mapper<LongWritable, Text, Text, IntWritable>
{

     
            public void map(LongWritable key, Text value, OutputCollector<Text, IntWritable> output, Reporter reporter) throws IOException
      {
            String line = value.toString();
            String col[]=line.split(",");
            String k=col[3];
            String year=col[2];
            int t1=Integer.parseInt(k);
            output.collect(new Text(year),new IntWritable(t1));
                 
            }
       
}
public static class MaxReducer extends MapReduceBase implements Reducer<Text, IntWritable, Text, IntWritable>
{
      
      public void reduce(Text key, Iterator<IntWritable> values, OutputCollector<Text, IntWritable> output, Reporter reporter) throws IOException
      {
    	  int max_temp = 0; 
          while (values.hasNext())
                      {
        	  int current=values.next().get();
                         if ( max_temp <  current)  
                        	 max_temp =  current;
                      }
          output.collect(key, new IntWritable(max_temp));

      }      
}
public static class App extends Configured implements Tool{   

public int run(String[] args) throws Exception
{
    
    JobConf conf = new JobConf(getConf(), App.class);
    conf.setJobName("HighestDriver");

 
    conf.setOutputKeyClass(Text.class);
    conf.setOutputValueClass(IntWritable.class);

    
    conf.setMapperClass(MaxMapper.class);
    conf.setReducerClass(MaxReducer.class);
    
    Path inp = new Path(args[0]);
    Path out = new Path(args[1]);
    
    FileInputFormat.addInputPath(conf, inp);
    FileOutputFormat.setOutputPath(conf, out);

    JobClient.runJob(conf);
    return 0;
}
}

public static void main(String[] args) throws Exception
{
   
int res = ToolRunner.run(new Configuration(), new App(),args);
    System.exit(res);
}

   
}

