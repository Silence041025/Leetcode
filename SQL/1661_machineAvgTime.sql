\c Leetcode

CREATE TABLE IF NOT EXISTS Activity (
    machine_id INT,
    process_id INT,
    activity_type VARCHAR(10) CHECK (activity_type IN ('start', 'end')),
    timestamp FLOAT
);

SELECT AEnd.machine_id,ROUND(AVG(AEnd.timestamp - AStart.timestamp)::NUMERIC,3) AS processing_time
FROM Activity AEnd INNER JOIN Activity AStart ON
AEnd.machine_id = AStart.machine_id AND
AEnd.process_id = AStart.process_id AND
AEnd.activity_type = 'end' AND
AStart.activity_type = 'start'
GROUP BY AEnd.machine_id;

