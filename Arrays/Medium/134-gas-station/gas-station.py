class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:

        # if sum(gas)<sum(cost):
        #     return -1

        idx=0
        fuel = 0
        curr_fuel = 0

        # net = [i-j for i,j in  zip(gas,cost)]
        # net = [i for i,v in enumerate(net) if v>0  ]

        # print(net)
        for pos in range(len(gas)):
            fuel_gain = gas[pos]-cost[pos]
            fuel += fuel_gain
            curr_fuel += fuel_gain
            if curr_fuel<0:
                curr_fuel = 0
                idx=pos+1

        return -1 if fuel<0 else idx

        