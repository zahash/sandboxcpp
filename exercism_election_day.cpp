#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace election
{

    // The election result struct is already created for you:

    struct ElectionResult
    {
        // Name of the candidate
        std::string name{};
        // Number of votes the candidate has
        int votes{};
    };

    std::ostream& operator<<(std::ostream& out, const ElectionResult& election_result) {
        out << "ElectionResult { \"" << election_result.name << "\" " << election_result.votes << " }";
        return out;
    }

    // TODO: Task 1
    // vote_count takes a reference to an `ElectionResult` as an argument and will
    // return the number of votes in the `ElectionResult.
    int vote_count(const ElectionResult &electionResult)
    {
        return electionResult.votes;
    }

    // TODO: Task 2
    // increment_vote_count takes a reference to an `ElectionResult` as an argument
    // and a number of votes (int), and will increment the `ElectionResult` by that
    // number of votes.
    void increment_vote_count(ElectionResult &electionResult, int votes)
    {
        electionResult.votes += votes;
    }

    // TODO: Task 3
    // determine_result receives the reference to a final_count and returns a
    // reference to the `ElectionResult` of the new president. It also changes the
    // name of the winner by prefixing it with "President". The final count is given
    // in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
    // `ElectionResults` of all the participating candidates.
    ElectionResult &determine_result(std::vector<ElectionResult> &results)
    {

        auto best_result = std::max_element(
            results.begin(), results.end(),
            [](const ElectionResult& a, const ElectionResult& b) { return a.votes < b.votes; }
        );

        best_result->name = "President " + best_result->name;
        return *best_result;
    }

} // namespace election

void foo(const std::vector<std::string>& v) {
    std::vector<std::string> other = v;
    other.back();
}

int main() {
    using namespace election;

    std::vector<ElectionResult> results = {
        {"Tammy Metzler", 0},
        {"Tracy Flick", 257},
        {"Paul Metzler", 256},
    };

    // for (const auto& result : results) {
    //     std::cout << result << std::endl;
    // }

    ElectionResult& winner = determine_result(results);
    std::cout << winner << std::endl;

    for (const auto& result : results) {
        std::cout << result << std::endl;
    }


    return 0;
}
