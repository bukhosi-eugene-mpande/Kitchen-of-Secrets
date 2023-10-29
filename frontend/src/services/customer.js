const BASE_URL = 'http://localhost:8000';

export async function fetchReservation(details) {
  try {
    const response = await fetch(`${BASE_URL}/reservation`, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify(details)
    });

    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }

    const data = await response.json();

    return data;
  } catch (error) {
    console.error('Error fetching data', error);

    throw error;
  }
}
