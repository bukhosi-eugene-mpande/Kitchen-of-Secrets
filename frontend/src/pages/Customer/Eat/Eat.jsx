import React, { useState, useEffect } from 'react';
import { CircularProgress, LinearProgress, Button } from '@mui/material';

function Eat() {
  const [progress, setProgress] = useState(0);
  const [foodStatus, setFoodStatus] = useState('waiting');

  useEffect(() => {
    const ws = new WebSocket('ws://localhost:8000/ws');

    ws.onmessage = (event) => {
      setProgress(0);
      setFoodStatus('eating');

      const timer = setInterval(() => {
        setProgress((oldProgress) => {
          if (oldProgress === 100) {
            setFoodStatus('done');
            clearInterval(timer);
            return 100;
          }

          return Math.min(oldProgress + 1, 100);
        });
      }, 600);
    };
  }, []);

  return (
    <div>
      {foodStatus === 'waiting' && (
        <>
          <CircularProgress />
          <p>Your food is being served...</p>
        </>
      )}
      {foodStatus === 'eating' && (
        <>
          <LinearProgress variant="determinate" value={progress} />
          <Button variant="contained" color="secondary">
            Complain about the food
          </Button>
        </>
      )}
      {foodStatus === 'done' && <p>You finished eating.</p>}
    </div>
  );
}

export default Eat;