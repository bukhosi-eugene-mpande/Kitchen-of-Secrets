import React, { useState, useEffect, useContext } from 'react';

import { CookContext } from './Cook';
import data from '../../../data/data.json';

import {
  Box,
  List,
  Button,
  Divider,
  ListItem,
  Typography,
  ListItemText,
  LinearProgress
} from '@mui/material';

function Pot() {
  const [progress, setProgress] = useState(0);
  const [cooking, setCooking] = useState(false);
  const requiredIngredients = data.requiredIngredients;

  const {
    pot,
    setOpen,
    isCooked,
    sendOrder,
    setIsCooked,
    removeFromPot,
    selectedOrder
  } = useContext(CookContext);

  useEffect(() => {
    let timer = null;

    if (cooking) {
      timer = setInterval(() => {
        setProgress((oldProgress) => {
          if (oldProgress === 100) {
            clearInterval(timer);
            return 100;
          }

          const newProgress = oldProgress + 100 / 30;

          return newProgress;
        });
      }, 1000);
    } else {
      setProgress(0);
    }
    return () => {
      clearInterval(timer);
    };
  }, [cooking]);

  const cook = () => {
    let sortedIngredients = [];

    for (let item of selectedOrder.food) {
      const food = requiredIngredients.find((food) => food.name === item.name);

      if (food) {
        sortedIngredients = [...sortedIngredients, ...food.ingredients];
      }
    }

    sortedIngredients.sort();

    const sortedPot = [...pot].sort();

    if (JSON.stringify(sortedPot) === JSON.stringify(sortedIngredients)) {
      setCooking(true);
      setTimeout(() => {
        setCooking(false);
        setIsCooked(true);
      }, 30000);
    } else {
      setOpen(true);
    }
  };

  return (
    <Box
      sx={{
        m: 2,
        p: 2,
        width: '100%',
        borderRadius: '4px',
        border: '4px solid',
        justifyContent: 'center',
        borderColor: 'primary.main'
      }}
    >
      <Typography variant='h3'>Pot</Typography>

      <Divider sx={{ my: 2 }} />

      <List>
        {pot.map((ingredient, index) => (
          <ListItem key={index}>
            <ListItemText primary={ingredient} sx={{ textAlign: 'center' }} />
            <Button
              size='small'
              variant='outlined'
              onClick={() => removeFromPot(ingredient)}
            >
              Remove
            </Button>
          </ListItem>
        ))}
      </List>

      {cooking ? (
        <LinearProgress variant='determinate' value={progress} />
      ) : (
        <Button
          color='primary'
          variant='contained'
          onClick={isCooked ? sendOrder : cook}
        >
          {isCooked ? 'Send to Customer' : 'Cook'}
        </Button>
      )}

      {cooking && <Typography variant='h6'>Cooking...</Typography>}
    </Box>
  );
}

export default Pot;
