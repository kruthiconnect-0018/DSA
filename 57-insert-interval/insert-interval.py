class Solution:
    def insert(self, intervals, newInterval):
        result = []

        start = newInterval[0]
        end = newInterval[1]

        for interval in intervals:
            current_start = interval[0]
            current_end = interval[1]

            # Current interval is completely before newInterval
            if current_end < start:
                result.append(interval)

            # Current interval is completely after newInterval
            elif current_start > end:
                result.append([start, end])
                start = current_start
                end = current_end

            # Overlapping interval
            else:
                start = min(start, current_start)
                end = max(end, current_end)

        # Add newInterval at the end if it hasn't been added
        result.append([start, end])

        return result