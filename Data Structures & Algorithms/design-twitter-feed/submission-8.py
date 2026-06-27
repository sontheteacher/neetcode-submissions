class Twitter:

    def __init__(self):
        self.count = 0
        self.followMap = defaultdict(set) # follower -> followee
        self.tweet = defaultdict(list) # userID -> (count, tweetID) count: 0, -1, -2, ... min-heap

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweet[userId].append([self.count, tweetId])
        self.count -= 1

    def getNewsFeed(self, userId: int) -> List[int]:
        heap = []
        res = [] # ordered starting from most recent

        self.followMap[userId].add(userId)
        # get a heap of all last element of each followee
        for followerId in self.followMap[userId]:
            if followerId in self.tweet:
                index = len(self.tweet[followerId]) - 1
                count, tweetId = self.tweet[followerId][index]
                heapq.heappush(heap, [count, tweetId, followerId, index - 1]) # store the next position for followerId
        
        while heap and len(res) < 10:
            count, tweetId, followeeId, index = heapq.heappop(heap)
            res.append(tweetId)
            if index >= 0:
                count, tweetId = self.tweet[followeeId][index]
                heapq.heappush(heap, [count, tweetId, followeeId, index - 1])
        return res


    def follow(self, followerId: int, followeeId: int) -> None:
        self.followMap[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.followMap[followerId].discard(followeeId)
