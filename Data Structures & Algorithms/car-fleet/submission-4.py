class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        sorted_data = sorted(zip(position, speed), key=lambda x: x[0], reverse = True)
        sorted_position, sorted_speed = zip(*sorted_data)

        sorted_position = list(sorted_position)
        sorted_speed = list(sorted_speed)

        print(sorted_speed, sorted_position)

        time = [0] * len(sorted_position)
        for i in range(len(time)):
            time[i] = (target - sorted_position[i]) / sorted_speed[i]
        count = 1
        curr_max = time[0]
        for i in range(1, len(time)):
            if time[i] > curr_max:
                count += 1
            curr_max = max(curr_max, time[i])
        print(time)
        return count