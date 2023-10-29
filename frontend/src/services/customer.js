const BASE_URL = 'http://localhost:8000/customer';

export async function fetchReservation() {
  try {
    const response = await fetch(`${BASE_URL}/reservation`);

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
