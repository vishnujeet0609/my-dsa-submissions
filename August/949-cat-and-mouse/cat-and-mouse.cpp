class Solution {
public:
    int catMouseGame(const vector<vector<int>>& graph) {
        constexpr int DRAW = 0, MOUSE_WIN = 1, CAT_WIN = 2, MOUSE = 0, CAT = 1;
        array<array<array<pair<int, size_t>, 2>, 50>, 50> game; // pair: first: winner, second: number of move options without loosing
        queue<array<int, 4>> resolved_states; // m, c, np, w
        
        for (auto c = 1; c < graph.size(); ++c) {
            resolved_states.push({ 0, c, CAT, game[0][c][CAT].first = MOUSE_WIN });
            resolved_states.push({ c, c, CAT, game[c][c][CAT].first = CAT_WIN });
            resolved_states.push({ c, c, MOUSE, game[c][c][MOUSE].first = CAT_WIN });
            
            for (auto m = 1; m < graph.size(); ++m) {
                game[m][c][MOUSE].second = graph[m].size();
                game[m][c][CAT].second = graph[c].size() - any_of(graph[c].begin(), graph[c].end(), [](int adj){ return adj == 0; });
            }
        }
        
        while (!resolved_states.empty()) {
            auto [m, c, np, w] = resolved_states.front();
            resolved_states.pop();
            for (const auto& moved_from: np == CAT? graph[m]: graph[c]) {
                auto [pm, pc, pp] = np == CAT? tuple(moved_from, c, MOUSE): tuple(m, moved_from, CAT);
                if ((pc != 0)
                    && (game[pm][pc][pp].first == DRAW)
                    && ((pp + 1 == w) || (--game[pm][pc][pp].second == 0))) {
                    if ((pm == 1) && (pc == 2) && (pp == MOUSE)) return w;
                    resolved_states.push({ pm, pc, pp, game[pm][pc][pp].first = w });
                }
            }
        }
        return DRAW;
    }
};