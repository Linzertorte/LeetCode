class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        result = []
        i = 0 
        while(i<len(intervals)):
            if(intervals[i].end>=newInterval.start):
                break
            result.append(intervals[i])
            i += 1
        #print intervals[i]
        #get last interval that start <= newInterval.end
        #
        j = i
        while(j<len(intervals)):
            if(intervals[j].start>newInterval.end):
                break
            j += 1
        j-=1
        if(i<=j):
            merge = Interval(min(newInterval.start,intervals[i].start),\
                             max(newInterval.end,intervals[j].end))
        else:
            merge = newInterval
        result.append(merge)
        j += 1
        while(j<len(intervals)):
            result.append(intervals[j])
            j +=1
            
        #for interval in result:
         #   print interval
        return result
