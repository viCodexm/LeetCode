struct Solution {
    int findRotateSteps(string ring, string key) {
        return tryLock(0, 0, ring, key, INT_MAX);
    }

    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }

    int tryLock(int ringIndex, int keyIndex, string ring, string key, int minSteps) {
        if (keyIndex == key.length())
            return 0;
        
        for (int i = 0; i < ring.length(); i++) {
            if (ring[i] == key[keyIndex]) {
                int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 +
                                            tryLock(i, keyIndex + 1, ring, key, INT_MAX);
                minSteps = min(minSteps, totalSteps);
            }
        }
        return minSteps;
    }
};