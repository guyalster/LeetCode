class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) 
    {
        vector<vector<int> > InitialHealth(dungeon.size(),vector<int>(dungeon[0].size(),INT_MAX));
        
        InitialHealth[dungeon.size() - 1][dungeon[0].size() - 1] = 
            std::max(1, 1 - dungeon[dungeon.size() - 1][dungeon[0].size() - 1]);
        
        for(int i = dungeon.size() - 1; i >= 0; i--)
        {
            for(int j = dungeon[0].size() - 1; j >= 0; j--)
            {
                if(i == dungeon.size() - 1 && j == dungeon[0].size() - 1)
                {
                    continue;
                }
                
                int I1 = INT_MAX;
                int I2 = INT_MAX;
                
                if(i + 1 != dungeon.size())
                {
                    I1 = dungeon[i][j] - InitialHealth[i + 1][j];
                    
                    if(I1 < 0)
                    {
                            I1 = std::abs(I1);
                    }
                    else
                    {
                        I1 = 1;
                    }
                }
                
                if(j + 1 != dungeon[0].size())
                {
                    I2 = dungeon[i][j] - InitialHealth[i][j + 1];
                    
                    if(I2 < 0)
                    {
                        I2 = std::abs(I2);
                    }
                    else
                    {
                        I2 = 1;
                    }
                }
                
                
                InitialHealth[i][j] = std::min(I1,I2);
                    
            }
        }
        
        return (InitialHealth[0][0]);
    }
};